/*************************************************************************
> File Name       : 15.3.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月28日  21时03分21秒
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
    virtual double net_price(size_t n) const { return n * m_price; }

    virtual ~Quote() = default;
};

double print_total(std::ostream &out, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    out << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

int main(int argc, const char *argv[])
{

    system("pause");
    return 0;
}