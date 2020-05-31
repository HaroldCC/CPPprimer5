/*************************************************************************
> File Name       : 6.5.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月30日  15时15分46秒
************************************************************************/
#include <iostream>

int abs(int value)
{
    return value > 0 ? value : -value;
}

int main(int argc, char const *argv[])
{
    std::cout << abs(10) << std::endl;
    std::cout << abs(-20) << std::endl;

    system("pause");
    return 0;
}