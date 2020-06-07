/*************************************************************************
> File Name       : 7.3.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月02日  21时30分42秒
************************************************************************/
#include <iostream>
#include "7.2.h"

int main(int argc, char const *argv[])
{
    Sales_data total;
    if (std::cin >> total.bookNo >> total.units_sold >> total.revenue)
    {
        Sales_data trans;
        while (std::cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
        {
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                std::cout << total.bookNo << " " << total.units_sold << " "
                          << total.revenue << std::endl;
                total = trans;
            }
        }
        std::cout << total.bookNo << " " << total.units_sold
                  << " " << total.revenue << std::endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }

    system("pause");
    return 0;
}