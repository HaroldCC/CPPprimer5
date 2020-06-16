/*************************************************************************
> File Name       : 11.32.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月16日  11时24分24秒
************************************************************************/
#include <iostream>
using std::cin, std::cout, std::endl;
#include <map>
using std::multimap;
#include <string>
using std::string;
#include <set>
using std::multiset;

int main(int argc, const char *argv[])
{
    multimap<string, string> authors{
        {"tom", "CPP"},
        {"jack", "Cpp2.0"},
        {"jane", "Cpp3.0"},
        {"jane", "Cpp4.0"},
        {"harold", "CppPractice"}};
    std::map<string, multiset<string>> orderAuthors;

    for (const auto &i : authors)
        orderAuthors[i.first].insert(i.second);

    string author = "jane", work = "Cpp3.0";

    for (const auto &i : orderAuthors)
    {
        cout << i.first << ": ";
        for (const auto &work : i.second)
            cout << work << " ";
        cout << endl;
    }

    system("pause");
    return 0;
}