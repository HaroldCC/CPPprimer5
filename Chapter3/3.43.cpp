/*************************************************************************
> File Name       : 3.43.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月18日  16时01分06秒
************************************************************************/
#include <iostream>

int main(int argc, char const *argv[])
{
    int array[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}};

    for (const int(&row)[4] : array)
        for (int col : row)
            std::cout << col << " ";
    std::cout << std::endl;

    for (size_t i = 0; i != 3; i++)
        for (size_t j = 0; j != 4; j++)
            std::cout << array[i][j] << " ";
    std::cout << std::endl;

    for (int(*row)[4] = array; row != array + 3; row++)
        for (int *col = *row; col != *row + 4; col++)
            std::cout << *col << " ";
    std::cout << std::endl;

    system("pause");
    return 0;
}
