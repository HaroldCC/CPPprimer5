/*************************************************************************
> File Name       : 3.22.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月11日  17时55分05秒
************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

int main(int argc, char const *argv[])
{
    std::vector<std::string> text;

    std::string line;
    while (std::getline(std::cin, line) && line != "!")
    {
        text.push_back(line);
    }

    // use range for
    // for (auto &word : text)
    // {
    //     for (auto &ch : word)
    //         if (isalpha(ch))
    //             ch = toupper(ch);
    //     std::cout << word << " ";
    // }

    // use iterator
    for (auto it = text.begin(); it != text.end(); it++)
    {
        for (auto str_it = it->begin(); str_it != it->end(); ++str_it)
        {
            *str_it = std::toupper(*str_it);
        }
        std::cout << *it << std::endl;
    }

    system("pause");
    return 0;
}
