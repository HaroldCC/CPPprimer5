/*************************************************************************
> File Name       : 14.45.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月28日  10时09分31秒
************************************************************************/
#include <string>
using std::string;
#include <iostream>

class Sales_data
{
    friend std::istream &operator>>(std::istream &in, Sales_data &sd);
    friend std::ostream &operator<<(std::ostream &out, const Sales_data &sd);
    friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);

private:
    string m_bookNo;
    unsigned m_unitsSold = 0;
    double m_revenue = 0;

private:
    double avg_price() const { return m_unitsSold ? m_revenue / m_unitsSold : 0; }

public:
    Sales_data(const string &s, unsigned n, double p)
        : m_bookNo(s), m_unitsSold(n), m_revenue(p) {}
    Sales_data() : Sales_data("", 0, 0.0f) {}
    Sales_data(const string &s) : Sales_data(s, 0, 0.0f) {}
    Sales_data(std::istream &in);

    Sales_data &operator=(const string &bookNo);
    Sales_data &operator+=(const Sales_data &rhs);

    explicit operator string() const { return m_bookNo; }
    explicit operator double() const { return avg_price(); }

    string isbn() const { return m_bookNo; }
};
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

std::ostream &operator<<(std::ostream &out, const Sales_data &sd)
{
    out << sd.isbn() << " " << sd.m_unitsSold << " " << sd.m_revenue
        << " " << sd.avg_price();
    return out;
}

std::istream &operator>>(std::istream &in, Sales_data &sd)
{
    double price = 0.0;
    in >> sd.m_bookNo >> sd.m_unitsSold >> price;
    if (in)
        sd.m_revenue = price * sd.m_unitsSold;
    else
        sd = Sales_data();
    return in;
}

Sales_data::Sales_data(std::istream &in) : Sales_data()
{
    in >> *this;
}

Sales_data &Sales_data::operator=(const string &bookNo)
{
    *this = Sales_data(bookNo);
    return *this;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
    m_unitsSold += rhs.m_unitsSold;
    m_revenue += rhs.m_revenue;
    return *this;
}

int main(int argc, char const *argv[])
{
    Sales_data cp5("C++ Primer 5th", 4, 106.5);
    std::cout << cp5 << std::endl;
    std::cout << static_cast<string>(cp5) << std::endl;
    std::cout << static_cast<double>(cp5) << std::endl;

    system("pause");
    return 0;
}
