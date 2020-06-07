/*************************************************************************
> File Name       : 7.4.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月02日  21时38分28秒
************************************************************************/
#ifndef CP5_EX07_04_H
#define CP5_EX07_04_H

#include <string>

class Person
{
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

#endif