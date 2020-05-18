/*************************************************************************
> File Name       : 3.8.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月10日  09时53分45秒
************************************************************************/
#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string str1("This is a string!");

    std::cout << "for loop...\n";
    std::cout << "before: " << str1 << std::endl;
    for (decltype(str1.size()) index = 0; index <= str1.size(); ++index)
    {
        str1[index] = 'X';
    }
    std::cout << "after: " << str1 << std::endl;

    std::string str2("This is a string!");

    std::cout << "while loop...\n";
    std::cout << "before: " << str2 << std::endl;
    decltype(str2.size()) index = 0;
    while (index <= str2.size() && !str2.empty())
    {
        str2[index++] = 'X';
    }
    std::cout << "after: " << str2 << std::endl;

    system("pause");

    return 0;
}