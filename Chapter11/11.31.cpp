/*************************************************************************
> File Name       : 11.31.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月16日  11时05分56秒
************************************************************************/
#include <iostream>
using std::cin, std::cout, std::endl;
#include <map>
using std::multimap;
#include <string>
using std::string;

int main(int argc, const char *argv[])
{
    multimap<string, string> authors{
        {"tom", "CPP"},
        {"jack", "Cpp2.0"},
        {"jane", "Cpp3.0"},
        {"jane", "Cpp4.0"},
        {"harold", "CppPractice"}};

    for (const auto &i : authors)
        cout << i.first << " " << i.second << endl;
    cout << endl;

    string author = "jane", work = "Cpp3.0";

    auto found = authors.find(author);
    auto count = authors.count(author);

    while (count)
    {
        if (found->second == work)
        {
            authors.erase(found);
            break;
        }
        ++found;
        --count;
    }

    for (const auto &i : authors)
        cout << i.first << " " << i.second << endl;

    system("pause");
    return 0;
}