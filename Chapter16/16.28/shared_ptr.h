
/*************************************************************************
> File Name       : shared_ptr.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年07月01日  11时01分50秒
************************************************************************/
#ifndef __SHARED_PTR_H__
#define __SHARED_PTR_H__

#include <functional>

/**
 * @brief 类调用：删除器
 * 
 */
struct Delete
{
    template <typename T>
    auto operator()(T *p) const
    {
        delete p;
    }
};

template <typename T>
class SharedPtr;

template <typename T>
auto swap(SharedPtr<T> &lhs, SharedPtr<T> &rhs)
{
    using std::swap;
    swap(lhs.m_ptr, rhs.m_ptr);
    swap(lhs.m_refCount, rhs.m_refCount);
    swap(lhs.m_deleter, rhs.m_deleter);
}

/**
 * @brief 类似STL中的shared_ptr
 * 
 * @tparam T 
 */
template <typename T>
class SharedPtr
{
private:
    T *m_ptr;
    std::size_t *m_refCount;            // 引用计数
    std::function<void(T *)> m_deleter; // 删除器
private:
    /**
     * @brief 减少引用计数和释放空间
     * 
     * @return auto 
     */
    auto decrement_and_destroy()
    {
        if (m_ptr && 0 == --*m_refCount)
            delete m_refCount, m_deleter(m_ptr);
        else if (!m_ptr)
            delete m_refCount;
        m_refCount = nullptr;
        m_ptr = nullptr;
    }

public:
    /**
     * @brief 默认构造
     * 
     */
    SharedPtr() : m_ptr(nullptr), m_refCount(new std::size_t(1)), m_deleter(Delete()) {}

    /**
     * @brief 使用原始指针构造
     * 
     * @param rawPtr 原始指针
     */
    explicit SharedPtr(T *rawPtr) : m_ptr(rawPtr), m_refCount(new std::size_t(1)), m_deleter(Delete()) {}

    /**
 * @brief 拷贝构造
 * 
 * @param sharedPtr 
 */
    SharedPtr(const SharedPtr &sharedPtr)
        : m_ptr(sharedPtr.m_ptr), m_refCount(sharedPtr.m_refCount), m_deleter(sharedPtr.m_deleter) { ++*m_refCount; }

    /**
     * @brief 移动构造
     * 
     * @param sharedPtr 
     */
    SharedPtr(SharedPtr &&sharedPtr) noexcept
        : m_ptr(sharedPtr.m_ptr), m_refCount(sharedPtr.m_refCount), m_deleter(std::move(sharedPtr.m_deleter))
    {
        sharedPtr.m_ptr = nullptr;
        sharedPtr.m_refCount = nullptr;
    }

    SharedPtr &operator=(const SharedPtr &rhs)
    {
        ++*rhs.m_refCount;
        decrement_and_destroy();
        m_ptr = rhs.m_ptr, m_refCount = rhs.m_refCount, m_deleter = rhs.m_deleter;
        return *this;
    }

    SharedPtr &operator=(SharedPtr &&rhs) noexcept
    {
        swap(*this, rhs);
        rhs.decrement_and_destroy();
        return *this;
    }

    /**
     * @brief 指针转换成bool
     * 
     * @return true 
     * @return false 
     */
    operator bool() const
    {
        return m_ptr ? true : false;
    }

    /**
     * @brief 解引用运算符
     * 
     * @return T& 
     */
    T &operator*() const
    {
        return *m_ptr;
    }

    /**
     * @brief 箭头运算符
     * 
     * @return T* 
     */
    T *operator->() const
    {
        return &*m_ptr;
    }

    /**
     * @brief 引用计数
     * 
     * @return auto 
     */
    auto use_count() const
    {
        return *m_refCount;
    }

    /**
     * @brief 获得内置指针
     * 
     * @return auto 
     */
    auto get() const
    {
        return m_ptr;
    }

    /**
     * @brief 是否有唯一的用户
     * 
     * @return auto 
     */
    auto unique() const
    {
        return 1 == *m_refCount;
    }

    auto swap(SharedPtr &rhs)
    {
        ::swap(*this, rhs);
    }

    /**
     * @brief 释放所指的对象（如果唯一）
     * 
     * @return auto 
     */
    auto reset()
    {
        decrement_and_destroy();
    }

    /**
     * @brief 使用新的原始指针重置
     * 
     * @param pointer 
     * @return auto 
     */
    auto reset(T *pointer)
    {
        if (m_ptr != pointer)
        {
            decrement_and_destroy();
            m_ptr = pointer;
            m_refCount = new std::size_t(1);
        }
    }

    /**
     * @brief 使用原始指针和删除器重置
     * 
     * @param pointer 
     * @param d 
     * @return auto 
     */
    auto reset(T *pointer, const std::function<void(T *)> &d)
    {
        reset(pointer);
        m_deleter = d;
    }

    ~SharedPtr()
    {
        decrement_and_destroy();
    }
};

#endif // __SHARED_PTR_H__