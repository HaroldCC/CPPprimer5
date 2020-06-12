/*************************************************************************
> File Name       : 9.15.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月10日  09时24分10秒
************************************************************************/
#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<int> ivec1{0, 1, 2};
    std::vector<int> ivec2{0, 1};
    std::vector<int> ivec3{0, 1, 2};

    // if (ivec1 == ivec2)
    //     std::cout << "ivec1 == ivec2" << std::endl;
    // else
    //     std::cout << "ivec1 != ivec2" << std::endl;

    // if (ivec1 == ivec3)
    //     std::cout << "ivec1 == ivec3" << std::endl;
    // else
    //     std::cout << "ivec1 != ivec3" << std::endl;

    std::cout << (ivec1 == ivec2 ? "ivec1 == ivec2" : "ivec1 != ivec2") << std::endl;
    std::cout << (ivec1 == ivec3 ? "ivec1 == ivec3" : "ivec1 != ivec3") << std::endl;

    system("pause");
    return 0;
}