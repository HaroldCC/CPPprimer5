/*************************************************************************
> File Name       : 10.28.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月13日  22时01分36秒
************************************************************************/
#include <iostream>
using std::cout, std::endl;
#include <vector>
using std::vector;
#include <list>
using std::list;
#include <algorithm>
using std::copy;
#include <iterator>
using std::back_inserter, std::front_inserter, std::inserter;

template <typename T>
void print(const T &sequence)
{
    for (auto i : sequence)
        cout << i << " ";
    cout << endl;
}

int main(int argc, const char *argv[])
{
    vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    list<int> ilst1;
    copy(ivec.cbegin(), ivec.cend(), back_inserter(ilst1));
    print(ilst1);

    list<int> ilst2;
    copy(ivec.cbegin(), ivec.cend(), front_inserter(ilst2));
    print(ilst2);

    list<int> ilst3;
    copy(ivec.cbegin(), ivec.cend(), inserter(ilst3, ilst3.begin()));
    print(ilst3);

    system("pause");
    return 0;
}