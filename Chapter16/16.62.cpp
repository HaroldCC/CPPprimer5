/*************************************************************************
> File Name       : 16.62.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年07月02日  15时07分34秒
************************************************************************/
#include <string>
using std::string;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

// struct Sales_data;

// istream &operator>>(istream &in, Sales_data &item);
// ostream &operator<<(ostream &out, const Sales_data &item);
// Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);

class Sales_data
{
    friend istream &operator>>(istream &in, Sales_data &item);
    friend ostream &operator<<(ostream &out, const Sales_data &item);
    friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
    friend bool operator==(const Sales_data &lhs, const Sales_data &rhs);
    friend class std::hash<Sales_data>;

private:
    string m_bookNo;
    unsigned m_unitsSold = 0;
    double m_revenue = 0.0;

private:
    inline double avg_price() const;

public:
    Sales_data(const string &bookNo, unsigned unitsSold, double price)
        : m_bookNo(bookNo), m_unitsSold(unitsSold), m_revenue(price * unitsSold)
    {
        cout << "Sales_data(const string&,unsigned,double)" << endl;
    }

    Sales_data() : Sales_data("", 0, 0.0) { cout << "Sales_data():Sales_data(\"\",0,0.0)" << endl; }

    Sales_data(const string &bookNo) : Sales_data(bookNo, 0, 0.0) { cout << "Sales_data(const string& bookNo):Sales_data(bookNo,0,0.0)" << endl; }

    Sales_data(istream &in) : Sales_data()
    {
        in >> *this;
        cout << "Sales_data(istream&):Sales_data()" << endl;
    }

    string isbn() const { return m_bookNo; }

    Sales_data &operator=(const string &bookData);

    Sales_data &operator+=(const Sales_data &rhs);
    Sales_data &operator-=(const Sales_data &rhs);
};

inline double Sales_data::avg_price() const
{
    if (m_unitsSold)
        return m_revenue / m_unitsSold;
    else
        return 0;
}

Sales_data &Sales_data::operator=(const std::string &rhs)
{
    *this = Sales_data(rhs);
    return *this;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
    m_unitsSold += rhs.m_unitsSold;
    m_revenue += rhs.m_revenue;

    return *this;
}

Sales_data &Sales_data::operator-=(const Sales_data &rhs)
{
    m_unitsSold -= rhs.m_unitsSold;
    m_revenue -= rhs.m_revenue;

    return *this;
}

istream &operator>>(istream &in, Sales_data &item)
{
    double price = 0;

    in >> item.m_bookNo >> item.m_unitsSold >> price;
    if (in)
        item.m_revenue = price * item.m_unitsSold;
    else
        item = Sales_data();

    return in;
}

ostream &operator<<(ostream &out, const Sales_data &item)
{
    out << item.isbn() << " " << item.m_unitsSold << " " << item.m_revenue << " " << item.avg_price();

    return out;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum += rhs;

    return sum;
}

bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() == rhs.isbn() &&
           lhs.m_unitsSold == rhs.m_unitsSold &&
           lhs.m_revenue == rhs.m_revenue;
}

#include <unordered_set>
using std::unordered_set;

namespace std
{
    template <>
    struct hash<Sales_data>
    {
        typedef size_t result_type;
        typedef Sales_data argument_type;
        size_t operator()(const Sales_data &sd) const;
    };
    size_t hash<Sales_data>::operator()(const Sales_data &sd) const
    {
        return hash<string>()(sd.m_bookNo) ^ hash<unsigned>()(sd.m_unitsSold) ^ hash<double>()(sd.m_revenue);
    }
} // namespace std

int main(int argc, char const *argv[])
{
    Sales_data sales1("001-01", 1, 100);
    Sales_data sales2;
    Sales_data sales3("001-02");

    cout << std::hex << std::hash<string>()("001-01") << endl;
    cout << std::hex << std::hash<unsigned>()(1) << endl;
    cout << std::hex << std::hash<double>()(100) << endl;

    std::unordered_multiset<Sales_data> SDset;
    SDset.emplace(sales1);
    SDset.emplace("001-03", 1, 200);
    SDset.emplace(sales3);

    for (const auto &i : SDset)
        cout << "the hash code of " << i.isbn() << ":\n0x" << std::hex
             << std::hash<Sales_data>()(i) << endl;

    system("pause");
    return 0;
}
