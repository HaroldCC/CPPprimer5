/*************************************************************************
> File Name       : 7.11.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月03日  08时26分49秒
************************************************************************/
#include "7.11.h"

int main(int argc, char const *argv[])
{
    Sales_data item1; // 默认构造
    print(std::cout, item1) << std::endl;

    Sales_data item2("0-2-1-78345-X"); // 单参构造
    print(std::cout, item2) << std::endl;

    Sales_data item3("0-201-78345-X", 3, 20.00); // 三参构造
    print(std::cout, item3) << std::endl;

    Sales_data item4(std::cin); // 输入构造
    print(std::cout, item4) << std::endl;

    system("pause");
    return 0;
}