/*************************************************************************
> File Name       : 9.46.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月10日  21时23分34秒
************************************************************************/
#include <iostream>
#include <string>

std::string adding_prefixes_suffixes(std::string &name, const std::string &prefixes, const std::string &suffixes)
{
    name.insert(0, prefixes);
    name.insert(name.size(), suffixes);
    return name;
}

int main(int argc, char const *argv[])
{
    std::string wNmae{"Wang"};

    std::cout << adding_prefixes_suffixes(wNmae, "Ms.", "Jr.") << std::endl;

    system("pause");
    return 0;
}