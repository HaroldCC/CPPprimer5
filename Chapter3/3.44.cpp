/*************************************************************************
> File Name       : 3.44.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月18日  16时09分09秒
************************************************************************/
#include <iostream>

int main(int argc, char const *argv[])
{
    int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    using int_array = int[4];
    for (int_array &p : ia)
        for (int q : p)
            std::cout << q << " ";
    std::cout << std::endl;

    for (size_t i = 0; i != 3; i++)
        for (size_t j = 0; j != 4; j++)
            std::cout << ia[i][j] << " ";
    std::cout << std::endl;

    for (int_array *p = ia; p != ia + 3; p++)
        for (int *q = *p; q != *p + 4; q++)
            std::cout << *q << " ";
    std::cout << std::endl;

    system("pause");
    return 0;
}
