/*************************************************************************
> File Name       : 9.16.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月10日  09时28分51秒
************************************************************************/
#include <iostream>
#include <vector>
#include <list>

int main(int argc, char const *argv[])
{
    std::vector<int> ivec1{0, 1, 2};
    std::vector<int> ivec2{0, 1, 2, 3};
    std::list<int> ilst{0, 1, 2};

    std::cout << (std::vector<int>(ilst.cbegin(), ilst.cend()) == ivec1 ? "ilst == ivec1" : "ilst != ivec1") << std::endl;
    std::cout << (std::vector<int>(ilst.cbegin(), ilst.cend()) == ivec2 ? "ilst == ivec2" : "ilst != ivec2") << std::endl;

    system("pause");
    return 0;
}