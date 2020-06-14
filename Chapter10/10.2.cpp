/*************************************************************************
> File Name       : 10.2.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月12日  17时27分19秒
************************************************************************/
#include <iostream>
#include <string>
#include <list>
#include <algorithm>

int main(int argc, char const *argv[])
{
    std::list<std::string> lstr{"hello", "hello", "Harold", "harold"};

    std::cout << "hello appear " << std::count(lstr.cbegin(), lstr.cend(), "hello") << std::endl;
    std::cout << "Harold appear " << std::count(lstr.cbegin(), lstr.cend(), "Harold") << std::endl;

    system("pause");
    return 0;
}