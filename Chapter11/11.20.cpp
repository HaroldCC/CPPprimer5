/*************************************************************************
> File Name       : 11.20.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月16日  10时47分29秒
************************************************************************/
#include <iostream>
using std::cin, std::cout, std::endl;
#include <map>
using std::map;
#include <string>
using std::string;

int main(int argc, const char *argv[])
{
    map<string, size_t> wordCount;
    for (string word; cin >> word;)
    {
        auto result = wordCount.insert({word, 1});
        if (!result.second)
            ++result.first->second;
    }
    for (const auto &count : wordCount)
        cout << count.first << " " << count.second
             << ((count.second > 1) ? " times." : " time.") << endl;

    system("pause");
    return 0;
}