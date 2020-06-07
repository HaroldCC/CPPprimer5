/*************************************************************************
> File Name       : 7.2.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月02日  21时25分38秒
************************************************************************/
#ifndef CP5_EX07_02_H
#define CP5_EX07_02_H

#include <string>

struct Sales_data
{
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

#endif