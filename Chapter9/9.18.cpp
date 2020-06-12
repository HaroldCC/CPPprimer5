/*************************************************************************
> File Name       : 9.18.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月10日  11时35分57秒
************************************************************************/
#include <iostream>
#include <string>
#include <deque>

int main(int argc, char const *argv[])
{
    std::string word;
    std::deque<std::string> dstr;
    while (std::cin >> word)
    {
        dstr.push_back(word);
    }

    for (auto i = dstr.cbegin(); i != dstr.cend(); ++i)
    {
        std::cout << *i << " ";
    }

    system("pause");
    return 0;
}