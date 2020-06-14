/*************************************************************************
> File Name       : 10.21.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月13日  18时22分50秒
************************************************************************/
#include <iostream>

int main(int argc, char const *argv[])
{
    int num = 5;

    auto f = [&num]() -> bool { return (num == 0 ? true : !(num--)); };

    while (!f())
        std::cout << num << std::endl;
    system("pause");
    return 0;
}