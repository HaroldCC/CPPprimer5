/*************************************************************************
> File Name       : 11.13.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月16日  10时10分54秒
************************************************************************/
#include <iostream>
using std::cin, std::cout, std::endl;
#include <tuple>
using std::pair;
#include <string>
using std::string;
#include <vector>
using std::vector;

int main(int argc, const char *argv[])
{
    vector<pair<string, int>> parVec;
    string inStr;
    int inNum;
    while (cin >> inStr >> inNum)
    {
        parVec.push_back(std::make_pair(inStr, inNum));
        // parVec.push_back(pair<string, int>(inStr, inNum));
        // parVec.push_back({inStr, inNum});
    }

    for (const auto &i : parVec)
        cout << i.first << " " << i.second << endl;

    system("pause");
    return 0;
}