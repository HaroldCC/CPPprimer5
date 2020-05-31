/*************************************************************************
> File Name       : 6.23.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月30日  21时47分45秒
************************************************************************/
#include <iostream>
void print(int i)
{
    std::cout << "print(0)" << i << std::endl;
}

void print(const int *beg, const int *end)
{
    while (beg != end)
    {
        std::cout << *beg++ << std::endl;
    }
}

void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i)
    {
        std::cout << ia[i] << std::endl;
    }
}

void print(const int (&ia)[2])
{
    for (auto i : ia)
        std::cout << i << std::endl;
}

int main(int argc, char const *argv[])
{
    int i = 0, j[2] = {0, 1};
    print(i);
    print(std::begin(j), std::end(j));
    print(j, std::end(j) - std::begin(j));
    print(j);

    system("pause");
    return 0;
}