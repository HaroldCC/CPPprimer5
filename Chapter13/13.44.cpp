/*************************************************************************
> File Name       : 13.44.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月26日  09时53分11秒
************************************************************************/
#include <memory>
using std::allocator;
using std::pair;
#include <initializer_list>
using std::initializer_list;
#include <algorithm>
using std::for_each;

class String
{
private:
    char *m_elements;
    char *m_end;
    allocator<char> m_alloc;

private:
    pair<char *, char *> alloc_n_copy(const char *beg, const char *end);
    void range_initializer(const char *beg, const char *end);
    void free();

public:
    String() : String("") {}
    String(const char *cStr);
    String(const String &theStr);
    String &operator=(const String &theStr);
    ~String();

    const char *c_str() const { return m_elements; }
    size_t size() const { return m_end - m_elements; }
    size_t length() const { return m_end - m_elements + 1; }
};

pair<char *, char *> String::alloc_n_copy(const char *beg, const char *end)
{
    auto str = m_alloc.allocate(end - beg);
    return {str, std::uninitialized_copy(beg, end, str)};
}

void String::range_initializer(const char *beg, const char *end)
{
    auto newStr = alloc_n_copy(beg, end);
    m_elements = newStr.first;
    m_end = newStr.second;
}

void String::free()
{
    if (m_elements)
    {
        for_each(m_elements, m_end, [this](char &c) { m_alloc.destroy(&c); });
        m_alloc.deallocate(m_elements, m_end - m_elements);
    }
}

String::String(const char *cStr)
{
    char *s1 = const_cast<char *>(cStr);
    while (*s1)
    {
        ++s1;
    }
    range_initializer(cStr, ++s1);
}

String::String(const String &theStr)
{
    range_initializer(theStr.m_elements, theStr.m_end);
}

String &String::operator=(const String &theStr)
{
    auto newStr = alloc_n_copy(theStr.m_elements, theStr.m_end);
    free();
    m_elements = newStr.first;
    m_end = newStr.second;
    return *this;
}

String::~String()
{
    free();
}

// test String
#include <iostream>
#include <vector>

void foo(String x)
{
    std::cout << x.c_str() << std::endl;
}

void bar(const String &x)
{
    std::cout << x.c_str() << std::endl;
}

String baz()
{
    String ret("world");
    return ret;
}

int main(int argc, const char *argv[])
{
    char text[] = "world";

    String s0;
    String s1("hello");
    String s2(s0);
    String s3 = s1;
    String s4(text);
    s2 = s1;

    foo(s1);
    bar(s1);
    foo("temporary");
    bar("temporary");
    String s5 = baz();

    std::vector<String> svec;
    svec.reserve(8);
    svec.push_back(s0);
    svec.push_back(s1);
    svec.push_back(s2);
    svec.push_back(s3);
    svec.push_back(s4);
    svec.push_back(s5);
    svec.push_back(baz());
    svec.push_back("good job");

    for (const auto &s : svec)
    {
        std::cout << s.c_str() << std::endl;
    }

    system("pause");
    return 0;
}