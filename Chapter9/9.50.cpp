/*************************************************************************
> File Name       : 9.50.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月10日  21时45分05秒
************************************************************************/
#include <iostream>
#include <vector>
#include <string>

int sum_of_int(const std::vector<std::string> &intStr)
{
    int sum = 0;
    for (auto i : intStr)
        sum += std::stoi(i);
    return sum;
}

float sum_of_float(const std::vector<std::string> &floatStr)
{
    float sum = 0;
    for (auto i : floatStr)
        sum += std::stof(i);
    return sum;
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> nums{"1", "2", "3", "4.5"};

    std::cout << sum_of_int(nums) << std::endl;
    std::cout << sum_of_float(nums) << std::endl;

    system("pause");
    return 0;
}