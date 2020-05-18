/*************************************************************************
> File Name       : 3.23.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月11日  18时23分02秒
************************************************************************/
#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        *it *= 2;
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    system("pause");
    return 0;
}
