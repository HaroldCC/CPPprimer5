/*************************************************************************
> File Name       : 15.5.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月28日  21时25分23秒
************************************************************************/
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

    double net_price(size_t buyBooksCount) const override;
};