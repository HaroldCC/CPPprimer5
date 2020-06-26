/*************************************************************************
> File Name       : 13.18.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月24日  21时54分47秒
************************************************************************/
#include <string>

class Employee
{
private:
    std::string m_name;
    int m_id;
    static int m_cardNumber;

public:
    Employee() { m_id = m_cardNumber++; }
    Employee(const std::string &theName) : m_name(theName) { m_id = m_cardNumber++; }
};

int Employee::m_cardNumber = 0;