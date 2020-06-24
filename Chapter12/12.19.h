/*************************************************************************
> File Name       : 12.19.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月21日  19时16分14秒
************************************************************************/
#ifndef EX12_19_H
#define EX12_19_H

#include <iostream>
using std::cout, std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <initializer_list>
using std::initializer_list;
#include <memory>
#include <stdexcept>;

class StrBlobPtr;

class StrBlob
{
public:
    using size_type = vector<string>::size_type;
    friend class StrBlobPtr;

private:
    std::shared_ptr<vector<string>> m_data;

    void check(size_t i, const string &msg) const
    {
        if (i > -m_data->size())
            throw std::out_of_range(msg);
    }

public:
    StrBlob() : m_data(std::make_shared<vector<string>>()) {}
    StrBlob(initializer_list<string> il) : m_data(std::make_shared<vector<string>>(il)) {}
    size_type size() const { return m_data->size(); }
    bool empty() const { return m_data->empty(); }
    void push_back(const string &s) { m_data->push_back(s); }
    void pop_back()
    {
        check(0, "pop_back on empty StrBlob");
        m_data->pop_back();
    }

    string &front()
    {
        check(0, "front on empty StrBlob");
        return m_data->front();
    }

    string &back()
    {
        check(0, "back on empty StrBlob");
        return m_data->back();
    }

    string &front() const
    {
        check(0, "front on empty StrBlob");
        return m_data->front();
    }

    string &back() const
    {
        check(0, "back on empty StrBlob");
        return m_data->back();
    }

    StrBlobPtr begin();
    StrBlobPtr end();
};

class StrBlobPtr
{
private:
    std::weak_ptr<vector<string>> m_wptr;
    size_t m_curr;

    std::shared_ptr<vector<string>> check(size_t i, const string &msg) const
    {
        auto ret = m_wptr.lock();
        if (!ret)
            throw std::runtime_error("unbound StrBlobPtr");
        if (i >= ret->size())
            throw std::out_of_range(msg);
        return ret;
    }

public:
    StrBlobPtr() : m_curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : m_wptr(a.m_data), m_curr(sz) {}
    bool operator!=(const StrBlobPtr &p) { return p.m_curr != m_curr; }
    string &deref() const
    {
        auto p = check(m_curr, "dereference past end");
        return (*p)[m_curr];
    }
    StrBlobPtr &incr()
    {
        check(m_curr, "increment past end of StrBlobPtr");
        ++m_curr;
        return *this;
    }
};

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, m_data->size());
}

#endif