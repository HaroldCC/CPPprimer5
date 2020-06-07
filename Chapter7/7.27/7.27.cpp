/*************************************************************************
> File Name       : 7.27.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月03日  09时32分21秒
************************************************************************/
#include <iostream>
#include "7.27.h"

int main(int argc, char const *argv[])
{
    Screen myScreen(5, 5, 'X');
    myScreen.display(std::cout);
    myScreen.move(4, 0).set('#').display(std::cout);
    std::cout << "\n";
    myScreen.display(std::cout);
    std::cout << "\n";

    system("pause");
    return 0;
}