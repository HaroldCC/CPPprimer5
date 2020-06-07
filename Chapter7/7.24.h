/*************************************************************************
> File Name       : 7.24.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月03日  09时06分58秒
************************************************************************/
#ifndef CP5_EX7_24_H
#define CP5_EX7_24_H

#include <string>

class Screen
{
public:
    using pos = std::string::size_type;

private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    std::string contents;

public:
    Screen() = default;
    Screen(pos ht, pos wd, char c)
        : height(ht), width(wd), contents(ht * wd, ' ') {}

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * width + c]; }
};

#endif