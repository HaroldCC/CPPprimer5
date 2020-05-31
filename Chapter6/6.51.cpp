/*************************************************************************
> File Name       : 6.51.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月31日  08时19分32秒
************************************************************************/
#include <iostream>

void print()
{
    std::cout << "print(): " << std::endl;
}

void print(int i)
{
    std::cout << "print(int): \n"
              << i << std::endl;
}

void print(int a, int b)
{
    std::cout << "print(int, int): \n"
              << a << " " << b << std::endl;
}

void print(double a, double b)
{
    std::cout << "print(double, double): \n"
              << a << " " << b << std::endl;
}

int main(int argc, char const *argv[])
{
    // print(2.56, 42); //!有多个 重载函数 "print" 实例与参数列表匹配: -- 函数 "print(int a, int b)" -- 函数 "print(double a, double b)" -- 参数类型为:  (double, int)
    print(42);
    print(42, 0);
    print(2.56, 3.14);

    system("pause");
    return 0;
}