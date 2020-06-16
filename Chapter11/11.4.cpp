/*************************************************************************
> File Name       : 11.4.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月15日  11时43分42秒
************************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <map>
using std::map;
#include <string>
using std::string;
#include <cctype>
using std::tolower;
#include <algorithm>
using std::remove_if;

int main(int argc, const char *argv[])
{
    map<string, size_t> wordCount;
    string word;
    while (cin >> word)
    {
        for (auto &ch : word)
            ch = tolower(ch);
        word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
        ++wordCount[word];
    }

    for (const auto &w : wordCount)
        cout << w.first << " occurs "
             << w.second << ((w.second > 1) ? " times." : " time.") << endl;

    system("pause");
    return 0;
}