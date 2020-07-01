/*************************************************************************
> File Name       : 15.15.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月29日  07时24分36秒
************************************************************************/
#include <string>
using std::string;
#include <iostream>

class Quote
{
private:
    string m_bookNo; // 书籍的ISBN编号
protected:
    double m_price; // 普通状态下不打折的价格
public:
    Quote() = default;
    Quote(const string &bookNo, double salesPrice) : m_bookNo(bookNo), m_price(salesPrice) {}

    string isbn() const { return m_bookNo; }

    // 给定数量书籍的销售总额
    virtual double net_price(size_t buyBooksCount) const { return buyBooksCount * m_price; }

    virtual void debug() const { std::cout << "bookNo: " << m_bookNo << " book prince: " << m_price; }

    virtual ~Quote() = default;
};

class Disc_quote : public Quote
{
protected:
    size_t m_quantity = 0;   // 折扣适用的购买量
    double m_discount = 0.0; // 折扣的小数值
public:
    Disc_quote() = default;
    Disc_quote(const string &bookNo, double price, size_t quantity, double discount)
        : Quote(bookNo, price), m_quantity(quantity), m_discount(discount) {}

    double net_price(size_t buyBooksCount) const override = 0;
};

class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string &bookNo, double price, size_t quantity, double discount)
        : Disc_quote(bookNo, price, quantity, discount) {}
    double net_price(size_t buyBooksCount) const override;
};