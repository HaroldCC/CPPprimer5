/*************************************************************************
> File Name       : 10.1.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月12日  17时21分43秒
************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<int> vec{0, 1, 2, 3, 3, 4, 4, 4, 5};

    std::cout << "3 appear " << std::count(vec.cbegin(), vec.cend(), 3) << " times." << std::endl;
    std::cout << "4 appear " << std::count(vec.cbegin(), vec.cend(), 4) << " times." << std::endl;
    std::cout << "5 appear " << std::count(vec.cbegin(), vec.cend(), 5) << " times." << std::endl;

    system("pause");
    return 0;
}