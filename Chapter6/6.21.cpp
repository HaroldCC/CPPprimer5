/*************************************************************************
> File Name       : 6.21.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月30日  16时23分58秒
************************************************************************/
#include <iostream>

int compare(int lhs, const int *rhs)
{
    return lhs > *rhs ? lhs : *rhs;
}

int main(int argc, char const *argv[])
{
    int a = 5, b = 10;
    std::cout << "biger: " << compare(a, &b) << std::endl;

    system("pause");
    return 0;
}