/*************************************************************************
> File Name       : 7.22.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月03日  08时58分30秒
************************************************************************/
#ifndef CP5_EX07_22_H
#define CP5_EX07_22_H

#include <string>
#include <iostream>

class Person
{
public:
    friend std::istream &read(std::istream &is, Person &person);
    friend std::ostream &print(std::ostream &os, const Person &person);

private:
    std::string name;
    std::string address;

public:
    const std::string &get_name() const
    {
        return name;
    }

    const std::string &get_address() const
    {
        return address;
    }
};

std::istream &read(std::istream &is, Person &rhs)
{
    is >> rhs.name >> rhs.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &rhs)
{
    os << rhs.name << " " << rhs.address;
    return os;
}

#endif