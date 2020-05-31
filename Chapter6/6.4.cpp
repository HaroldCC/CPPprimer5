/*************************************************************************
> File Name       : 6.4.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月30日  15时02分24秒
************************************************************************/
#include <iostream>
#include <string>

long factorial(int value)
{
    return value > 1 ? value * factorial(value - 1) : 1;
}

int main(int argc, char const *argv[])
{
    std::string const prompt = "Enter a number within [1, 13) :\n";
    std::string const out_of_range = "Out of range, please try again.\n";
    for (int i; std::cout << prompt, std::cin >> i;)
    {
        if (i < 1 || i > 12)
        {
            std::cout << out_of_range;
            continue;
        }
        std::cout << factorial(i) << std::endl;
    }

    system("pause");
    return 0;
}