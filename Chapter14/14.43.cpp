/*************************************************************************
> File Name       : 14.43.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月28日  07时33分53秒
************************************************************************/
#include <iostream>
using std::cout, std::endl;
#include <functional>
using std::modulus;
#include <vector>
using std::vector;
#include <algorithm>

int main(int argc, const char *argv[])
{
    vector<int> ivec{1, 3, 5, 7, 9};

    int input;
    std::cin >> input;

    modulus<int> mod;

    auto predicator = [&](int i) { return 0 == mod(input, i); };

    auto isDivisiable = std::all_of(ivec.begin(), ivec.end(), predicator);
    std::cout << (isDivisiable ? "yes" : "no") << std::endl;

    system("pause");
    return 0;
}