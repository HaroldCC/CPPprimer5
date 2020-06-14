/*************************************************************************
> File Name       : 10.6.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月12日  17时37分18秒
************************************************************************/
#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>

int main(int argc, char const *argv[])
{
    std::vector<int> vec{0, 1, 2, 3, 4};

    // std::fill_n(std::back_inserter(vec), 10, 0);
    std::fill_n(vec.begin(), vec.size(), 0);

    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;

    system("pause");
    return 0;
}