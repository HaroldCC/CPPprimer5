/*************************************************************************
> File Name       : 9.14.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月10日  08时58分18秒
************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <list>

int main(int argc, char const *argv[])
{
    std::list<const char *> lchar{"hello world!"};
    std::cout << lchar.size() << std::endl;
    // std::vector<std::string> vstr(lchar.cbegin(), lchar.cend());
    std::vector<std::string> vstr;
    vstr.assign(lchar.cbegin(), lchar.cend());
    std::cout << vstr.size() << std::endl;

    for (auto i = vstr.cbegin(); i != vstr.cend(); i++)
    {
        std::cout << *i << std::endl;
    }

    system("pause");
    return 0;
}