/*************************************************************************
> File Name       : 3.35.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月18日  10时23分56秒
************************************************************************/
#include <iostream>

int main(int argc, char const *argv[])
{
    int array[5];

    for (auto i = array; i != array + 5; i++)
    {
        *i = 0;
    }
    for (auto i : array)
        std::cout << array[i];
    std::cout << std::endl;

    system("pause");
    return 0;
}
