/*************************************************************************
> File Name       : 13.40.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月25日  17时40分48秒
************************************************************************/
#include <memory>
#include <string>

using std::pair;
using std::string;

class StrVec
{
private:
    void check_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }

    pair<string *, string *> alloc_n_copy(const string *beg, const string *end);
    void free();
    void reallocate();
    void alloc_n_move(size_t newCap);
    void range_initialize(const string *beg, const string *end);

private:
    std::allocator<std::string> alloc;
    string *m_elements;
    string *m_first_free;
    string *m_cap;

public:
    StrVec() : m_elements(nullptr), m_first_free(nullptr), m_cap(nullptr) {}
    StrVec(const std::initializer_list<string> ilstr) { range_initialize(ilstr.begin(), ilstr.end()); }
    StrVec(const StrVec &theStrVec);
    StrVec &operator=(const StrVec &theStrVec);
    ~StrVec();
    void push_back(const string &str);
    size_t size() const { return m_first_free - m_elements; }
    size_t capacity() const { return m_cap - m_elements; }
    string *begin() const { return m_elements; }
    string *end() const { return m_first_free; }

    void reserve(size_t newCap);
    void resize(size_t count);
    void resize(size_t count, const string &value);
};

pair<string *, string *> StrVec::alloc_n_copy(const string *beg, const string *end)
{
    auto data = alloc.allocate(end - beg);
    return {data, std::uninitialized_copy(beg, end, data)};
}

void StrVec::free()
{
    if (m_elements)
        for (auto p = m_first_free; p != m_elements;)
            alloc.destroy(--p);
    alloc.deallocate(m_elements, m_cap - m_elements);
}

void StrVec::reallocate()
{
    auto newCapacity = size() ? 2 * size() : 1;
    alloc_n_move(newCapacity);
}

void StrVec::alloc_n_move(size_t newCap)
{
    auto newData = alloc.allocate(newCap);
    auto dest = newData;
    auto elem = m_elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    m_elements = newData;
    m_first_free = dest;
    m_cap = m_elements + newCap;
}

void StrVec::range_initialize(const string *beg, const string *end)
{
    auto newData = alloc_n_copy(beg, end);
    m_elements = newData.first;
    m_first_free = m_cap = newData.second;
}

StrVec::StrVec(const StrVec &theStrVec)
{
    auto newData = alloc_n_copy(theStrVec.begin(), theStrVec.end());
    m_elements = newData.first;
    m_first_free = m_cap = newData.second;
}

StrVec &StrVec::operator=(const StrVec &theStrVec)
{
    auto data = alloc_n_copy(theStrVec.begin(), theStrVec.end());
    free();
    m_elements = data.first;
    m_first_free = m_cap = data.second;
    return *this;
}

StrVec::~StrVec()
{
    free();
}

void StrVec::push_back(const string &str)
{
    check_n_alloc();
    alloc.construct(m_first_free++, str);
}

void StrVec::reserve(size_t newCap)
{
    if (newCap < capacity())
        return;
    alloc_n_move(newCap);
}

void StrVec::resize(size_t count)
{
    resize(count, string());
}

void StrVec::resize(size_t count, const string &value)
{
    if (count > size())
    {
        if (count > capacity())
            reserve(count * 2);
        for (size_t i = size(); i != count; ++i)
            alloc.construct(m_first_free++, value);
    }
    else if (count < size())
    {
        while (m_first_free != m_elements + count)
        {
            alloc.destroy(--m_first_free);
        }
    }
}
