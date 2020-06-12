/*************************************************************************
> File Name       : 9.47.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月10日  21时29分29秒
************************************************************************/
#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string str{"ab2c3d7R4E6"};
    std::string numbers{"0123456789"};

    for (size_t pos = 0; (pos = str.find_first_of(numbers, pos)) != std::string::npos; ++pos)
        std::cout << str[pos] << " ";

    std::cout << std::endl;
    for (size_t pos = 0; (pos = str.find_first_not_of(numbers, pos)) != std::string::npos; ++pos)
        std::cout << str[pos] << " ";
    std::cout << std::endl;

    system("pause");
    return 0;
}