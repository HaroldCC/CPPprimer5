

/*************************************************************************
> File Name       : unique_ptr.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年07月01日  15时52分50秒
************************************************************************/
#ifndef __UNIQUE_PTR_H__
#define __UNIQUE_PTR_H__

#include <iostream>

class DebugDelete
{
private:
    std::ostream &m_out;

public:
    DebugDelete(std::ostream &out = std::cerr) : m_out(out) {}

    template <typename T>
    void operator()(T *p) const
    {
        m_out << "DebugDelete UniquePtr." << std::endl;
        delete p;
    }
};

template <typename T, typename D>
class UniquePtr;

template <typename T, typename D>
void swap(UniquePtr<T, D> &lhs, UniquePtr<T, D> &rhs);

template <typename T, typename D = DebugDelete>
class UniquePtr
{
    friend void swap<T, D>(UniquePtr<T, D> &lhs, UniquePtr<T, D> &rhs);

private:
    T *m_ptr = nullptr;
    D m_deleter = D();

public:
    // 防止复制和拷贝
    UniquePtr(const UniquePtr &) = delete;
    UniquePtr &operator=(const UniquePtr &) = delete;

    // 默认构造
    UniquePtr() = default;

    /**
     * @brief  使用原始指针初始化
     * 
     * @param pointer 
     */
    explicit UniquePtr(T *pointer) : m_ptr(pointer) {}

    /**
     * @brief 移动构造函数
     * 
     * @param uniquePtr 
     */
    UniquePtr(UniquePtr &&uniquePtr) noexcept : m_ptr(uniquePtr.m_ptr) { uniquePtr.m_ptr = nullptr; }

    UniquePtr &operator=(UniquePtr &&rhs) noexcept
    {
        if (this->m_ptr != rhs.m_ptr)
        {
            m_deleter(m_ptr);
            m_ptr = nullptr;
            ::swap(*this, rhs);
        }
        return *this;
    }

    UniquePtr &operator=(std::nullptr_t n) noexcept
    {
        if (n == nullptr)
        {
            m_deleter(m_ptr);
            m_ptr = nullptr;
        }
        return *this;
    }

    T &operator*() const { return *m_ptr; }
    T *operator->() const { return &*m_ptr; }
    operator bool() const { return m_ptr ? true : false; }

    /**
     * @brief 获得原始指针
     * 
     * @return T* 
     */
    T *get() const noexcept { return m_ptr; }

    void swap(UniquePtr<T, D> &rhs) { ::swap(*this, rhs); }

    /**
     * @brief 释放空间，并将指针置空
     * 
     */
    void reset() noexcept
    {
        m_deleter(m_ptr);
        m_ptr = nullptr;
    }

    /**
     * @brief 释放空间，将指针指向pointer
     * 
     * @param pointer 
     */
    void reset(T *pointer) noexcept
    {
        m_deleter(m_ptr);
        m_ptr = pointer;
    }

    /**
     * @brief 将指针置空并返回
     * 
     * @return T* 
     */
    T *release()
    {
        T *ret = m_ptr;
        m_ptr = nullptr;
        return ret;
    }

    ~UniquePtr() { m_deleter(m_ptr); }
};

template <typename T, typename D>
inline void swap(UniquePtr<T, D> &lhs, UniquePtr<T, D> &rhs)
{
    using std::swap;
    swap(lhs.m_ptr, rhs.m_ptr);
    swap(lhs.m_deleter, rhs.m_deleter);
}

#endif // __UNIQUE_PTR_H__