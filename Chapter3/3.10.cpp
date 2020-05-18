/*************************************************************************
> File Name       : 3.10.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月10日  10时08分26秒
************************************************************************/
#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char const *argv[])
{
    std::string str("I'm a coder! And I am coding now!!!");
    for (auto c : str)
        if (!std::ispunct(c))
            std::cout << c;
    std::cout << std::endl;

    system("pause");
    return 0;
}
