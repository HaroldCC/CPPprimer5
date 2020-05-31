/*************************************************************************
> File Name       : 6.30.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月30日  22时17分36秒
************************************************************************/
#include <iostream>

bool str_subrange(const std::string &str1, const std::string &str2)
{
    if (str1.size() == str2.size())
        return str1 == str2;

    auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();

    for (decltype(size) i = 0; i != size; ++i)
    {
        if (str1[i] != str2[i])
            return; //! return-statement with no value, in function returning 'bool' [-fpermissive]
    }
}

int main(int argc, char const *argv[])
{
    std::cout << str_subrange("string", "str") << std::endl;

    system("pause");
    return 0;
}