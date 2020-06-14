/*************************************************************************
> File Name       : 10.20.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月13日  18时16分00秒
************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

size_t word_length_more_than_6(const std::vector<std::string> &words)
{
    return std::count_if(words.cbegin(), words.cend(),
                         [](const std::string &str) { return str.size() > 6; });
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> vstr{"string", "hello world", "world wide", "str", "word", "hell"};

    std::cout << word_length_more_than_6(vstr) << std::endl;

    system("pause");
    return 0;
}