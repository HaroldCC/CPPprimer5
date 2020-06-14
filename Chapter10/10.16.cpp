/*************************************************************************
> File Name       : 10.16.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月13日  15时34分14秒
************************************************************************/
#include <iostream>
#include <string>
#include <vector>
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

    std::stable_sort(words.begin(), words.end(),
                     [](const std::string &lhs, const std::string &rhs) { return lhs.size() < rhs.size(); });

    auto firstMeet = std::find_if(words.begin(), words.end(), [sz](const std::string &lhs) { return lhs.size() >= sz; });

    std::for_each(firstMeet, words.end(), [](const std::string &str) { std::cout << str << " "; });
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> vstr{"string", "hello", "world", "str", "hell", "word"};

    greater_than_given_length_words(vstr, 3);

    system("pause");
    return 0;
}