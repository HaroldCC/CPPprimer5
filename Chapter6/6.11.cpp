/*************************************************************************
> File Name       : 6.11.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月30日  15时38分39秒
************************************************************************/
#include <iostream>

using std::cout;
using std::endl;

void reset(int &value)
{
    value = 0;
}

int main(int argc, char const *argv[])
{
    int i = 42;
    reset(i);
    std::cout << i << std::endl;

    system("pause");
    return 0;
}