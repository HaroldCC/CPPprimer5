/*************************************************************************
> File Name       : 15.26.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月29日  10时47分13秒
************************************************************************/
#include <string>
using std::string;
#include <iostream>

class Quote
{
    friend bool operator!=(const Quote &lhs, const Quote &rhs);

private:
    string m_bookNo; // 书籍的ISBN编号
protected:
    double m_price; // 普通状态下不打折的价格
public:
    Quote() { std::cout << "default constructing Quote.\n"; }
    Quote(const string &bookNo, double salesPrice) : m_bookNo(bookNo), m_price(salesPrice)
    {
        std::cout << "Quote:constructor taking 2 parameters.\n";
    }

    // 复制构造
    Quote(const Quote &theQuote) : m_bookNo(theQuote.m_bookNo), m_price(theQuote.m_price)
    {
        std::cout << "Quote:copy constructing.\n";
    }

    // 移动构造
    Quote(Quote &&theQuote) noexcept : m_bookNo(std::move(theQuote.m_bookNo)), m_price(std::move(theQuote.m_price))
    {
        std::cout << "Quote:move constructing.\n";
    }

    // 复制构造运算符
    Quote &operator=(const Quote &rhs)
    {
        if (*this != rhs)
        {
            m_bookNo = rhs.m_bookNo;
            m_price = rhs.m_price;
        }
        std::cout << "Quote : operator=().\n ";
        return *this;
    }

    // 复制移动运算符
    Quote &operator=(Quote &&rhs) noexcept
    {
        if (*this != rhs)
        {
            m_bookNo = rhs.m_bookNo;
            m_price = rhs.m_price;
        }
        std::cout << "Quote: move operator=().\n";
        return *this;
    }

    string isbn() const
    {
        return m_bookNo;
    }

    // 给定数量书籍的销售总额
    virtual double net_price(size_t buyBooksCount) const { return buyBooksCount * m_price; }

    virtual void debug() const { std::cout << "bookNo: " << m_bookNo << " book prince: " << m_price; }

    virtual ~Quote() { std::cout << "destructing Quote.\n"; }
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
    Bulk_quote() { std::cout << "default constructing Bilk_quote.\n"; }
    Bulk_quote(const string &bookNo, double price, size_t quantity, double discount)
        : Disc_quote(bookNo, price, quantity, discount) { std::cout << "Bulk_quote: constructor taking 4 parameters.\n"; }

    // 复制构造
    Bulk_quote(const Bulk_quote &theBq) : Disc_quote(theBq) { std::cout << "Bulk_quote: copy constructor.\n"; }

    // 移动构造
    Bulk_quote(Bulk_quote &&theBq) noexcept : Disc_quote(std::move(theBq)) { std::cout << "Bulk_quote: move constructor.\n"; }

    // 复制构造运算符
    Bulk_quote &operator=(const Bulk_quote &rhs)
    {
        Disc_quote::operator=(rhs);
        std::cout << "Bilk_quote: copy=().\n";
        return *this;
    }

    // 复制移动运算符
    Bulk_quote &operator=(Bulk_quote &&rhs) noexcept
    {
        Disc_quote::operator=(std::move(rhs));
        std::cout << "Bulk_quote: move =().\n";
        return *this;
    }

    double net_price(size_t buyBooksCount) const override;

    ~Bulk_quote() override { std::cout << "destructing Bulk_quote.\n"; }
};
inline bool operator!=(const Quote &lhs, const Quote &rhs)
{
    return lhs.m_bookNo == rhs.m_bookNo && lhs.m_price == rhs.m_price;
}
