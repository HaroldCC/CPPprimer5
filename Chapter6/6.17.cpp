/*************************************************************************
> File Name       : 6.17.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月30日  16时02分02秒
************************************************************************/
#include <iostream>
#include <string>
#include <cstring>

using std::cout;
using std::endl;
using std::string;

bool any_upper(const string &str)
{
    for (auto ch : str)
        if (std::isupper(ch))
            return true;
    return false;
}

void change_lower(string &str)
{
    for (auto ch : str)
        ch = std::tolower(ch);
}

int main(int argc, char const *argv[])
{
    string str("String Sample");

    if (any_upper(str))
        cout << "have upper letters." << endl;
    else
        cout << "not have upper letters." << endl;

    change_lower(str);
    cout << str << std::endl;

    system("pause");
    return 0;
}