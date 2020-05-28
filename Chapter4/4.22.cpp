/*************************************************************************
> File Name       : 4.22.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月21日  09时50分59秒
************************************************************************/
#include <iostream>

int main(int argc, char const *argv[])
{
    unsigned grade[] = {50, 54, 60, 65, 70, 75, 80, 90, 95};
    for (auto i : grade)
        std::cout << i << ": "
                  << ((i > 90) ? "high pass"
                               : (i < 60)
                                     ? "fail"
                                     : (i < 75)
                                           ? "low pass"
                                           : "pass")
                  << std::endl;

    system("pause");
    return 0;
}