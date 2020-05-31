/*************************************************************************
> File Name       : 6.42.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月31日  07时30分32秒
************************************************************************/
#include <iostream>
#include <string>

std::string make_plural(size_t ctr, const std::string &word, const std::string &ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}

int main(int argc, char const *argv[])
{
    std::cout << make_plural(1, "success", "es") << " " << make_plural(1, "failure") << std::endl;
    std::cout << make_plural(2, "success", "es") << " " << make_plural(2, "failure") << std::endl;

    system("pause");
    return 0;
}