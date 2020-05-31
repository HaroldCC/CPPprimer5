/*************************************************************************
> File Name       : 6.47.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月31日  07时56分07秒
************************************************************************/
#include <iostream>
#include <vector>

// #define NDEBUG

void print_vector(std::vector<int>::const_iterator beg, std::vector<int>::const_iterator end)
{
#ifndef NDEBUG
    std::cout << "vector.size = " << end - beg << std::endl;
#endif
    if (beg == end)
    {
        std::cout << "over!" << std::endl;
        return;
    }
    std::cout << *beg << " ";
    print_vector(++beg, end);
}

int main(int argc, char const *argv[])
{
    std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    print_vector(vec.cbegin(), vec.cend());

    system("pause");
    return 0;
}