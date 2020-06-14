/*************************************************************************
> File Name       : 10.9.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月12日  18时11分06秒
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

int main(int argc, char const *argv[])
{
    std::vector<std::string> svec{"hello", "hello", "world", "harold", "harl", "harold", "end"};
    eliminate_duplicate_words(svec);

    system("pause");
    return 0;
}