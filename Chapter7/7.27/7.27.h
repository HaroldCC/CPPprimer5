/*************************************************************************
> File Name       : 7.27.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月03日  09时15分41秒
************************************************************************/
#ifndef CP5_EX7_27_H
#define CP5_EX7_27_H

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

    void do_display(std::ostream &os) const { os << contents; }

public:
    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(pos ht, pos wd, char c)
        : height(ht), width(wd), contents(ht * wd, c) {}

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * width + c]; }

    inline Screen &move(pos r, pos c)
    {
        cursor = r * width + c;
        return *this;
    }

    inline Screen &set(char c)
    {
        contents[cursor] = c;
        return *this;
    }

    inline Screen &set(pos r, pos c, char ch)
    {
        contents[r * width + c] = ch;
        return *this;
    }

    const Screen &display(std::ostream &os) const
    {
        do_display(os);
        return *this;
    }

    Screen &display(std::ostream &os)
    {
        do_display(os);
        return *this;
    }
};

#endif