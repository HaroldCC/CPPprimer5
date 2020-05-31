/*************************************************************************
> File Name       : 6.25.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月30日  22时04分17秒
************************************************************************/
#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string str;
    for (int i = 1; i != argc; ++i)
        str += std::string(argv[i]) + " ";
    std::cout << str << std::endl;

    system("pause");
    return 0;
}