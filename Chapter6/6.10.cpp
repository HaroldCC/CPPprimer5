/*************************************************************************
> File Name       : 6.10.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月30日  15时33分26秒
************************************************************************/
#include <iostream>

void swap_value(int *lhs, int *rhs)
{
    int temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}

int main(int argc, char const *argv[])
{
    int a = 1, b = 2;

    std::cout << "before swap a = " << a << " b = " << b << std::endl;
    swap_value(&a, &b);
    std::cout << "after swap a = " << a << " b = " << b << std::endl;

    system("pause");
    return 0;
}