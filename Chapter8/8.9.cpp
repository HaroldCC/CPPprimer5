/*************************************************************************
> File Name       : 8.9.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月07日  22时10分46秒
************************************************************************/
#include <iostream>
#include <sstream>

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
    std::istringstream iss("hello world!");
    readata_form_stream(iss);

    system("pause");
    return 0;
}