/*************************************************************************
> File Name       : 6.27.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月30日  22时08分43秒
************************************************************************/
#include <iostream>
#include <initializer_list>

int sum_initializer_list(const std::initializer_list<int> &il)
{
    int sum = 0;
    for (auto i : il)
        sum += i;
    return sum;
}

int main(int argc, char const *argv[])
{
    auto il = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << sum_initializer_list(il) << std::endl;

    system("pause");
    return 0;
}