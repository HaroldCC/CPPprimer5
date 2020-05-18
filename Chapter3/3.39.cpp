/*************************************************************************
> File Name       : 3.39.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月18日  13时01分44秒
************************************************************************/
#include <iostream>
#include <string>
#include <cstring>

int main(int argc, char const *argv[])
{
    std::string s1("this is string1");
    std::string s2("this is string2");
    std::string s3("this is string1");

    if (s1 == s2)
        std::cout << "s1 == s2" << std::endl;
    else if (s1 < s2)
        std::cout << "s1 < s2" << std::endl;
    else
        std::cout << "s1 > s2" << std::endl;
    if (s1 == s3)
        std::cout << "s1 == s3" << std::endl;
    else if (s1 < s3)
        std::cout << "s1 < s3" << std::endl;
    else
        std::cout << "s1 > s3" << std::endl;

    const char str1[] = {"this is str1"};
    const char str2[] = {"this is str2"};
    const char str3[] = {"this is str1"};
    if (std::strcmp(str1, str2) == 0)
        std::cout << "str1 == str2" << std::endl;
    else if (std::strcmp(str1, str2) > 0)
        std::cout << "str1 > str2" << std::endl;
    else
        std::cout << "str1 < str2" << std::endl;
    if (std::strcmp(str1, str3) == 0)
        std::cout << "str1 == str3" << std::endl;
    else if (std::strcmp(str1, str3) > 0)
        std::cout << "str1 > str3" << std::endl;
    else
        std::cout << "str1 < str3" << std::endl;

    system("pause");
    return 0;
}
