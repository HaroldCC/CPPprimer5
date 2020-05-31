/*************************************************************************
> File Name       : 6.38.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月31日  07时16分21秒
************************************************************************/
#include <iostream>

int odd[] = {1, 3, 5, 7, 9};
int event[] = {0, 2, 4, 6, 8};
auto arrPtr(int i) -> int (&)[5]
{
    return (i % 2) ? odd : event;
}

int main(int argc, char const *argv[])
{
    std::cout << &odd << "\n"
              << &event << "\n"
              << arrPtr(3) << std::endl;

    system("pause");
    return 0;
}