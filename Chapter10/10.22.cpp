/*************************************************************************
> File Name       : 10.22.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月13日  19时19分31秒
************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

bool word_length_less_than_6(const std::string &words, std::string::size_type sz)
{
    return words.size() <= sz;
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> vstr{"hello world", "a string", "hell", "world"};

    std::cout << std::count_if(vstr.cbegin(), vstr.cend(),
                               std::bind(word_length_less_than_6, std::placeholders::_1, 6))
              << std::endl;

    system("pause");
    return 0;
}