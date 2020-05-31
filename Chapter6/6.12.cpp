/*************************************************************************
> File Name       : 6.12.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月30日  15时52分52秒
************************************************************************/
#include <iostream>

void swap_value(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main(int argc, char const *argv[])
{
    int a = 10, b = 20;
    std::cout << "befor swap a = " << a << " b = " << b << std::endl;
    swap_value(a, b);
    std::cout << "after swap a = " << a << " b = " << b << std::endl;

    system("pause");
    return 0;
}