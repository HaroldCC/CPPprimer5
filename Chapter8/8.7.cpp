/*************************************************************************
> File Name       : 8.7.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月07日  22时01分04秒
************************************************************************/
#include <iostream>
#include <fstream>
#include "../Chapter7/7.21/7.21.h"

int main(int argc, char const *argv[])
{
    std::ifstream input(argv[1]);
    std::ofstream ouput(argv[2]);

    Sales_data total;
    if (read(input, total))
    {
        Sales_data trans;
        while (read(input, trans))
        {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(ouput, total) << std::endl;
                total = trans;
            }
        }
        print(ouput, total) << std::endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
    }

    system("pause");
    return 0;
}