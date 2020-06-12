/*************************************************************************
> File Name       : 9.19.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月10日  11时55分53秒
************************************************************************/
#include <iostream>
#include <string>
#include <list>

int main(int argc, char const *argv[])
{
    std::string word;
    std::list<std::string> lstr;
    while (std::cin >> word)
    {
        lstr.push_back(word);
    }

    for (auto i = lstr.cbegin(); i != lstr.cend(); ++i)
    {
        std::cout << *i << " ";
    }

    system("pause");
    return 0;
}