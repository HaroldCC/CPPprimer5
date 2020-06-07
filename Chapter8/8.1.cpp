/*************************************************************************
> File Name       : 8.1.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月07日  11时11分19秒
************************************************************************/
#include <iostream>
#include <string>

std::istream &readata_form_stream(std::istream &is)
{
    std::string tmp;
    while (is >> tmp)
    {
        std::cout << tmp << std::endl;
    }
    is.clear();
    return is;
}

int main(int argc, char const *argv[])
{
    readata_form_stream(std::cin);

    system("pause");
    return 0;
}