/*************************************************************************
> File Name       : 9.24.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月10日  16时11分41秒
************************************************************************/
#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<int> ivec{0, 1, 2, 3, 4, 5};
    std::vector<int> empVec;

    empVec.push_back(ivec.at(0));

    std::cout << empVec.front() << std::endl;

    for (auto i : ivec)
        std::cout << i << " ";
    std::cout << std::endl;

    system("pause");
    return 0;
}