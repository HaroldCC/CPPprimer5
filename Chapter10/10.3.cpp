/*************************************************************************
> File Name       : 10.3.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月12日  17时32分29秒
************************************************************************/
#include <iostream>
#include <vector>
#include <numeric>

int main(int argc, char const *argv[])
{
    std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "sum = " << std::accumulate(vec.cbegin(), vec.cend(), 0);

    system("pause");
    return 0;
}