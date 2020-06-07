/*************************************************************************
> File Name       : 7.1.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月02日  21时05分09秒
************************************************************************/
#include <iostream>
#include <string>

struct Sales_data
{
    std::string boolNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main(int argc, char const *argv[])
{
    Sales_data total;
    if (std::cin >> total.boolNo >> total.units_sold >> total.revenue)
    {
        Sales_data trans;
        while (std::cin >> trans.boolNo >> trans.units_sold >> trans.revenue)
        {
            if (total.boolNo == trans.boolNo)
            {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            }
            else
            {
                std::cout << total.boolNo << " " << total.units_sold << " "
                          << total.revenue << std::endl;
                total = trans;
            }
        }
        std::cout << total.boolNo << " " << total.units_sold
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