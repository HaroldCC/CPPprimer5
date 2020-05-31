/*************************************************************************
> File Name       : 6.7.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月30日  15时27分00秒
************************************************************************/
#include <iostream>

int sample()
{
    static int callTimes = 0;
    return callTimes++;
}

int main(int argc, char const *argv[])
{
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << i + 1 << " times called "
                  << ", return value " << sample() << std::endl;
    }

    system("pause");
    return 0;
}