/*************************************************************************
> File Name       : 10.24.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月13日  20时20分06秒
************************************************************************/
#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>

bool check_size(const std::string &str, size_t sz)
{
    return str.size() < sz;
}

int main(int argc, char const *argv[])
{
    std::vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::string str("12345");

    auto it = std::find_if(ivec.cbegin(), ivec.cend(), std::bind(check_size, str, std::placeholders::_1));
    if (it != ivec.cend())
        std::cout << *it << " ";

    system("pause");
    return 0;
}