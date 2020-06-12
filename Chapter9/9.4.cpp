/*************************************************************************
> File Name       : 9.4.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月08日  17时27分29秒
************************************************************************/
#include <iostream>
#include <vector>

bool find(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int num)
{
    while (begin != end)
    {
        if (*begin == num)
            return true;
        ++begin;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    std::vector<int> veci{0, 1, 2, 3, 4, 5, 6, 7};

    std::cout << find(veci.cbegin(), veci.cend(), 0) << std::endl;

    system("pause");
    return 0;
}