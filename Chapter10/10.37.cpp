/*************************************************************************
> File Name       : 10.37.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月14日  17时40分57秒
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
using std::back_inserter;

int main(int argc, const char *argv[])
{
    vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> ilst;

    copy(ivec.cbegin() + 4, ivec.cbegin() + 7, back_inserter(ilst));

    for (auto i : ilst)
        cout << i << " ";
    cout << endl;

    system("pause");
    return 0;
}