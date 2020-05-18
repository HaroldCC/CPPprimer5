/*************************************************************************
> File Name       : 3.20.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月11日  11时03分28秒
************************************************************************/
#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<int> nums;
    int num = 0;
    while (std::cin >> num)
    {
        nums.push_back(num);
    }

    if (nums.empty())
    {
        std::cout << "nums is empty!\n";
        return -1;
    }

    if (nums.size() == 1)
    {
        std::cout << "nums only have 1 num!\n";
        return -1;
    }

    std::cout << nums.size() << std::endl;

    std::cout << "part1______________________________________________\n";
    for (decltype(nums.size()) i = 0; i < nums.size() - 1; i++)
        std::cout << nums[i] + nums[i + 1] << " ";
    std::cout << std::endl;

    std::cout << "part2______________________________________________\n";
    // 当元素为奇数个时，最中间的数与自己相加
    auto size = (nums.size() + 1) / 2;
    for (decltype(nums.size()) i = 0; i != size; i++)
        std::cout << nums[i] + nums[nums.size() - i - 1] << " ";
    std::cout << std::endl;

    system("pause");
    return 0;
}
