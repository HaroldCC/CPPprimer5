/*************************************************************************
> File Name       : 10.11.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月12日  18时24分07秒
************************************************************************/
#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

void eliminate_duplicate_words(std::vector<std::string> &words)
{
    std::sort(words.begin(), words.end());
    auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique, words.end());

    for (auto i : words)
        std::cout << i << " ";
    std::cout << std::endl;
}

bool isShorter(const std::string &s1, const std::string &s2)
{
    return s1.size() < s2.size();
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> svec{"hello", "hello", "world", "harold", "harl", "harold", "end"};

    eliminate_duplicate_words(svec);

    std::stable_sort(svec.begin(), svec.end(), isShorter);

    for (auto i : svec)
        std::cout << i << " ";
    std::cout << std::endl;

    system("pause");
    return 0;
}