/*************************************************************************
> File Name       : 10.36.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月14日  17时30分47秒
************************************************************************/
#include <iostream>
using std::cout, std::endl;
#include <list>
using std::list;
#include <algorithm>
using std::find;

int main(int argc, const char *argv[])
{
    list<int> ilst{0, 1, 2, 3, 4, 5, 0, 6, 7, 0, 8, 9};

    cout << ilst.size() << endl;

    auto it = find(ilst.crbegin(), ilst.crend(), 0);

    cout << std::distance(it, ilst.crend()) << endl;

    system("pause");
    return 0;
}