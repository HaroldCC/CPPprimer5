/*************************************************************************
> File Name       : 16.4.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年07月01日  09时12分44秒
************************************************************************/

template <typename Iterator, typename Value>
Iterator find(Iterator first, Iterator last, const Value &value)
{
    for (; first != last && *first != value; ++first)
        ;
    return first;
}

#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <list>
using std::list;
#include <string>
using std::string;

int main(int argc, const char *argv[])
{
    vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8};

    cout << (ivec.cend() != find(ivec.cbegin(), ivec.cend(), 7)) << endl;
    cout << (ivec.cend() != find(ivec.cbegin(), ivec.cend(), 9)) << endl;

    list<string> slst{"hello", "hell", "world", "harold"};

    cout << (slst.cend() != find(slst.cbegin(), slst.cend(), "hell")) << endl;
    cout << (slst.cend() != find(slst.cbegin(), slst.cend(), "helle")) << endl;

    system("pause");
    return 0;
}