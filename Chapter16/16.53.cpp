/*************************************************************************
> File Name       : 16.53.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年07月02日  10时59分40秒
************************************************************************/
#include <iostream>

template <typename T>
std::ostream &print(std::ostream &out, const T &t)
{
    return out << t;
}

template <typename T, typename... Arg>
std::ostream &print(std::ostream &out, const T &t, const Arg &... arg)
{
    out << t << ", ";
    return print(out, arg...);
}

int main(int argc, const char *argv[])
{
    print(std::cout, "str1", 1, 2, 3, 4, 5);

    system("pause");
    return 0;
}