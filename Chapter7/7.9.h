/*************************************************************************
> File Name       : 7.9.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月02日  21时38分28秒
************************************************************************/
#ifndef CP5_EX07_09_H
#define CP5_EX07_09_H

#include <string>
#include <iostream>

struct Person
{
    std::string name;
    std::string address;

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