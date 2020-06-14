/*************************************************************************
> File Name       : 10.27.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月13日  21时48分03秒
************************************************************************/
#include <iostream>
using std::cout, std::endl;
#include <vector>
using std::vector;
#include <list>
using std::list;
#include <algorithm>
using std::unique_copy;
#include <iterator>
using std::back_inserter;

int main(int argc, const char *argv[])
{
    vector<int> ivec{0, 1, 2, 3, 4, 4, 5, 5, 6, 7};
    list<int> ilst;

    unique_copy(ivec.cbegin(), ivec.cend(), back_inserter(ilst));

    for (auto i : ilst)
        cout << i << " ";
    cout << endl;

    for (auto i : ivec)
        cout << i << " ";
    cout << endl;

    system("pause");
    return 0;
}