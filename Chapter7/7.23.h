/*************************************************************************
> File Name       : 7.23.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月03日  09时01分22秒
************************************************************************/
#ifndef CP5_EX7_23_H
#define CP5_EX7_23_H

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
        : height(ht), width(wd), contents(ht * wd, c) {}

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * width + c]; }
};

Screen::Screen(/* args */)
{
}

Screen::~Screen()
{
}

#endif