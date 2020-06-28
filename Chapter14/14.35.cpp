/*************************************************************************
> File Name       : 14.35.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月27日  14时57分10秒
************************************************************************/
#include <iostream>

class PrintString
{
private:
    std::istream &m_in;

public:
    PrintString(std::istream &in = std::cin) : m_in(in) {}
    std::string operator()() const
    {
        std::string str;
        std::getline(m_in, str);
        return m_in ? str : std::string();
    }
};

int main(int argc, const char *argv[])
{
    PrintString printer;
    std::cout << printer();

    system("pause");
    return 0;
}