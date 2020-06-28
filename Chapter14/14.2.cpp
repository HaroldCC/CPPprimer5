/*************************************************************************
> File Name       : 14.2.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月26日  17时23分38秒
************************************************************************/

#include <string>
#include <iostream>

class Sales_data
{
    friend std::istream &operator>>(std::istream &in, Sales_data &sd);
    friend std::ostream &operator<<(std::ostream &out, const Sales_data &sd);
    friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);

private:
    std::string m_bookNo;
    unsigned m_units_sold = 0;
    double m_revenue = 0.0;

private:
    inline double avg_price() const;

public:
    Sales_data(const std::string &s, unsigned n, double p)
        : m_bookNo(s), m_units_sold(n), m_revenue(p) {}
    Sales_data() : Sales_data("", 0, 0.0f) {}
    Sales_data(const std::string &s) : Sales_data(s, 0, 0.0f) {}
    Sales_data(std::istream &in);

    Sales_data &operator+=(const Sales_data &rhs);
    std::string isbn() const { return m_bookNo; }
};
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

std::ostream &operator<<(std::ostream &out, const Sales_data &sd)
{
    out << sd.isbn() << " " << sd.m_units_sold << " "
        << sd.m_revenue << " " << sd.avg_price();
    return out;
}

std::istream &operator>>(std::istream &in, Sales_data &sd)
{
    double price = 0.0;
    in >> sd.m_bookNo >> sd.m_units_sold >> price;
    if (in)
        sd.m_revenue = price * sd.m_units_sold;
    else
        sd = Sales_data();
    return in;
}

inline double Sales_data::avg_price() const
{
    return m_units_sold ? m_revenue / m_units_sold : 0;
}

Sales_data::Sales_data(std::istream &in)
{
    in >> *this;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
    m_units_sold += rhs.m_units_sold;
    m_revenue += rhs.m_revenue;
    return *this;
}
