/*************************************************************************
> File Name       : 12.23.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月22日  10时01分47秒
************************************************************************/
#include <iostream>
#include <string>
#include <cstring>

int main(int argc, const char *argv[])
{
    const char *cstring1 = "hello";
    const char *cstring2 = "world!";
    char *cstring = new char[std::strlen(cstring1) + std::strlen(cstring2) + 1]();
    std::strcat(cstring, cstring1);
    std::strcat(cstring, cstring2);
    std::cout << cstring << std::endl;

    std::string str1 = "hello";
    std::string str2 = "world";
    std::strcpy(cstring, (str1 + str2).c_str());
    std::cout << cstring << std::endl;

    system("pause");
    return 0;
}