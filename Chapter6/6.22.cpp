/*************************************************************************
> File Name       : 6.22.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月30日  16时31分51秒
************************************************************************/
#include <iostream>

void swap_int_pointer(int **lhs, int **rhs)
{
    int *temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}

int main(int argc, char const *argv[])
{
    int a = 11, b = 22;
    int *pa = &a;
    int *pb = &b;
    swap_int_pointer(&pa, &pb);
    std::cout << " a = " << *pa << " b = " << *pb << std::endl;

    system("pause");
    return 0;
}