/*************************************************************************
> File Name       : 10.17.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月13日  17时54分07秒
************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void remove_duplicate_words(std::vector<std::string> &words)
{
    std::sort(words.begin(), words.end());
    auto uniqueEnd = std::unique(words.begin(), words.end());
    words.erase(uniqueEnd, words.end());
}

void greater_than_given_length_words(std::vector<std::string> &words, std::vector<std::string>::size_type sz)
{
    remove_duplicate_words(words);

    auto order = std::stable_partition(words.begin(), words.end(), [sz](const std::string &lhs) { return lhs.size() >= sz; });

    for (auto it = words.cbegin(); it != order; ++it)
        std::cout << *it << " ";
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> vstr{"string", "hello", "world", "str", "hell", "word"};

    greater_than_given_length_words(vstr, 3);

    system("pause");
    return 0;
}