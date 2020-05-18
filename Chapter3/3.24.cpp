/*************************************************************************
> File Name       : 3.24.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月11日  21时58分51秒
************************************************************************/
#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<int> vec;
    int num = 0;
    while (std::cin >> num)
    {
        vec.push_back(num);
    }

    if (vec.size() < 2)
    {
        std::cout << "vec need 2 nums!\n";
        return -1;
    }

    std::cout << "part1______________________________________\n";
    for (auto it = vec.cbegin(); it + 1 != vec.cend(); it++)
        std::cout << *it + *(it + 1) << " ";
    std::cout << std::endl;

    std::cout << "part2______________________________________\n";
    for (auto lft = vec.cbegin(), rht = vec.cend() - 1; lft <= rht; lft++, rht--)
        std::cout << *lft + *rht << " ";
    std::cout << std::endl;

    system("pause");
    return 0;
}
