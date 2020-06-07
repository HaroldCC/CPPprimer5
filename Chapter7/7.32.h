/*************************************************************************
> File Name       : 7.32.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月03日  12时40分29秒
************************************************************************/
#ifndef CP5_EX7_32_H
#define CP5_EX7_32_H

#include <string>
#include <vector>

class Screen;

class Window_mgr
{
private:
    std::vector<Screen> screens;

public:
    using ScreenIndex = std::vector<Screen>::size_type;

    inline void clear(ScreenIndex i)
    {
        Screen &s = screens[i];
        s.contents = std::string(s.height * s.width, ' ');
    }
};

class Screen
{
    friend void Window_mgr::clear(ScreenIndex);

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