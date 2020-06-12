/*************************************************************************
> File Name       : 9.45.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月10日  21时08分49秒
************************************************************************/
#include <iostream>
#include <string>

std::string add_prefix_and_suffix(std::string &name, const std::string &prefix, const std::string &suffix)
{
    name.insert(name.begin(), prefix.cbegin(), prefix.cend());
    return name.append(suffix);
}

int main(int argc, char const *argv[])
{
    std::string wNmae = "Wang";
    std::cout << add_prefix_and_suffix(wNmae, "Ms.", "III");

    system("pause");
    return 0;
}