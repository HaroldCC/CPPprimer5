/*************************************************************************
> File Name       : 3.31.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月15日  08时06分26秒
************************************************************************/
#include <iostream>

int main(int argc, char const *argv[])
{
    int array[10];
    for (int i = 0; i < 10; i++)
    {
        array[i] = i;
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    system("pause");
    return 0;
}
