/*************************************************************************
> File Name       : 3.40.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月18日  13时17分09秒
************************************************************************/
#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
    const char cstr1[] = "Hello";
    const char cstr2[] = "World";

    const size_t new_size = std::strlen(cstr1) + strlen(" ") + std::strlen(cstr2) + 1;
    char cstr3[new_size];

    std::strcpy(cstr3, cstr1);
    std::strcat(cstr3, " ");
    std::strcat(cstr3, cstr2);

    std::cout << cstr3 << std::endl;

    system("pause");
    return 0;
}
