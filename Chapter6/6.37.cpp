/*************************************************************************
> File Name       : 6.37.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月31日  07时04分12秒
************************************************************************/
#include <iostream>
#include <string>

std::string (&func())[10]; // 返回数组引用的函数声明 -> 普通声明

//using strArrRef = std::string[10]; // or
typedef std::string strArrRef[10];
strArrRef &func(); // 返回数组引用的函数声明 -> 使用类型别名

auto func() -> std::string (&)[10]; // 返回数组引用的函数声明 -> 使用位置返回类型

std::string strArr[10];
decltype(strArr) &func(); // 返回数组引用的函数声明 -> 使用decltype关键字

int main(int argc, char const *argv[])
{

    system("pause");
    return 0;
}