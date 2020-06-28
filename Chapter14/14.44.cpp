/*************************************************************************
> File Name       : 14.44.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月28日  08时50分35秒
************************************************************************/
#include <iostream>
using std::cin, std::cout, std::endl;
#include <map>
using std::map;
#include <string>
using std::string;
#include <functional>

int add(int i, int j)
{
    return i + j;
}

auto mod = [](int i, int j) {
    if (j == 0)
    {
        cout << "error!" << std::endl;
    }
    else
        return i % j;
};

struct Div
{
    int operator()(int i, int j) const
    {
        if (j == 0)
            cout << "error!" << std::endl;
        else
            return (i / j);
    }
};

auto binops = map<string, std::function<int(int, int)>>{
    {"+", add},                                // 函数指针
    {"-", std::minus<int>()},                  // 库仿函数
    {"*", [](int i, int j) { return i * j; }}, // 匿名lambda
    {"/", Div()},                              //自定义仿函数
    {"%", mod}                                 // 命名的lambda
};

int main(int argc, const char *argv[])
{
    while (cout << "input the nums and operator: ", true)
    {
        int lhs, rhs;
        string op;
        cin >> lhs >> op >> rhs;
        cout << binops[op](lhs, rhs) << endl;
    }

    system("pause");
    return 0;
}