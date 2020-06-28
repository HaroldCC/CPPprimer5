/*************************************************************************
> File Name       : 14.36.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月27日  21时33分43秒
************************************************************************/
#include <iostream>
#include <vector>

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

int main(int argc, char const *argv[])
{
    std::vector<std::string> strVec;
    PrintString printer;

    for (std::string tmp; !(tmp = printer()).empty();)
        strVec.push_back(tmp);

    for (auto i : strVec)
        std::cout << i << " ";
    std::cout << std::endl;

    system("pause");
    return 0;
}
