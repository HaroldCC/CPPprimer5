/*************************************************************************
> File Name       : 11.3.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月15日  11时34分33秒
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
    string word;
    while (cin >> word)
        ++wordCount[word];

    for (const auto &w : wordCount)
        cout << w.first << " occurs "
             << w.second << ((w.second > 1) ? " times." : " time.") << endl;

    system("pause");
    return 0;
}