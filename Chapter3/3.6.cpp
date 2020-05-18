/*************************************************************************
> File Name       : 3.6.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月10日  09时40分27秒
************************************************************************/
#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string str("This is a string!");

    std::cout << "before: " << str << std::endl;
    for (auto &s : str)
        s = 'X';
    std::cout << "after: " << str << std::endl;

    system("pause");

    return 0;
}
