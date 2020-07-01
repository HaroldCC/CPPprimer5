/*************************************************************************
> File Name       : 15.6.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月28日  21时35分38秒
************************************************************************/
#include <iostream>
#include <string>
using std::string;

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

    virtual ~Quote() = default;
};

class Bulk_quote : public Quote
{
private:
    size_t m_minQty = 0;     // 适用折扣政策的最低购买量
    double m_discount = 0.0; // 折扣额
public:
    Bulk_quote() = default;
    Bulk_quote(const string &bookNo, double price, size_t quantity, double discount)
        : Quote(bookNo, price), m_minQty(quantity), m_discount(discount) {}

    // double net_price(size_t buyBooksCount) const override;
};

double print_total(std::ostream &out, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    out << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

int main(int argc, const char *argv[])
{
    Quote q("C++ Primer 5th", 132);
    Bulk_quote bq("C++ Primer 5th", 132, 5, 5.3);

    print_total(std::cout, q, 10);
    print_total(std::cout, bq, 10);

    system("pause");
    return 0;
}