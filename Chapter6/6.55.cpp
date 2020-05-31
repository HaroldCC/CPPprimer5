/*************************************************************************
> File Name       : 6.55.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月31日  08时32分29秒
************************************************************************/
#include <iostream>
#include <vector>

int sum(int a, int b)
{
    return a + b;
}

int minus(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return b != 0 ? a / b : 0;
}

std::vector<decltype(sum) *> funcPointer;

int main(int argc, char const *argv[])
{
    funcPointer.push_back(sum);
    funcPointer.push_back(minus);
    funcPointer.push_back(multiply);
    funcPointer.push_back(divide);

    for (auto i : funcPointer)
        std::cout << i(6, 2) << " ";

    system("pause");
    return 0;
}