/*************************************************************************
> File Name       : 16.12.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年07月01日  10时05分56秒
************************************************************************/
#include <memory>
using std::make_shared;
using std::shared_ptr;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <initializer_list>
using std::initializer_list;

template <typename T>
class Blob
{
public:
    typedef vector<T>::size_type size_type;

private:
    shared_ptr<vector<T>> m_data;

private:
    // 当m_data[i]不合法时，抛出异常信息
    void check(size_type i, const string &msg) const;

public:
    Blob();
    Blob(initializer_list<T> il);

    size_type size() const { return m_data->size(); }
    bool empty() const { return m_data->empty(); }

    void push_back(const T &t) { m_data->push_back(t); }
    void push_back(T &&t) { m_data->push_back(std::move(t)); }
    void pop_back();

    T &back();
    T &operator[](size_type i);

    const T &back() const;
    const T &operator[](size_type i) const;
};
template <typename T>
void Blob<T>::check(size_type i, const string &msg) const
{
    if (i >= m_data->size())
        throw std::out_of_range(msg);
}

template <typename T>
Blob<T>::Blob() : m_data(make_shared<vector<T>>())
{
}

template <typename T>
Blob<T>::Blob(initializer_list<T> il) : m_data(make_shared<vector<T>>(il))
{
}

template <typename T>
void Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob.");
    m_data->pop_back();
}

template <typename T>
T &Blob<T>::back()
{
    check(0, "back on empty Blob.");
    return m_data->back();
}

template <typename T>
const T &Blob<T>::back() const
{
    check(0, "back on empty Blob.");
    return m_data->back();
}

template <typename T>
const T &Blob<T>::operator[](size_type i) const
{
    check(i, "subscript out of range.");
    return (*m_data)[i];
}

template <typename T>
T &Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range.");
    return (*m_data)[i];
}

template <typename T>
class BlobPtr;

template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);

template <typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);

template <typename T>
class BlobPtr
{
    friend bool operator==<T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
    friend bool operator<< T>(const BlobPtr<T> &lsh, const BlobPtr<T> &rhs);

private:
    std::weak_ptr<vector<T>> m_wptr;
    std::size_t m_curr;

private:
    shared_ptr<vector<T>> check(std::size_t i, string &msg) const;

public:
    BlobPtr() : m_curr(0) {}
    BlobPtr(Blob<T> &bl, std::size_t sz = 0) : m_wptr(bl.m_data), m_curr(sz) {}

    T &operator*() const
    {
        auto p = check(m_curr, "dereference past end.");
        return (*p)[m_curr];
    }

    BlobPtr &operator++();
    BlobPtr &operator--();

    BlobPtr operator++(int);
    BlobPtr operator--(int);
};

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator++()
{
    check(m_curr, "increment past end of StrBlob.");
    ++m_curr;
    return *this;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator--()
{
    --m_curr;
    check(m_curr, "decrement past begin of BlobPtr.");
    return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
    BlobPtr ret = *this;
    --*this;
    return ret;
}

template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    if (lhs.m_wptr.lock() != rhs.m_wptr.lock())
    {
        throw std::runtime_error("ptrs to different Blobs!");
    }
    return lhs.i == rhs.i;
}

template <typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    if (lhs.m_wptr.lock() != rhs.m_wptr.lock())
    {
        throw std::runtime_error("ptrs to different Blobs!");
    }
    return lhs.i < rhs.i;
}
