/*************************************************************************
> File Name       : 3.17.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月11日  09时44分49秒
************************************************************************/
#include <iostream>
#include <vector>
#include <string>

int main(int argc, char const *argv[])
{
    std::vector<std::string> strWord;

    std::string str;
    while (std::cin >> str && str != "@") //  当输入@后程序停止
    {
        strWord.push_back(str);
        std::cin.get();
    }

    for (auto &str : strWord)
        for (auto &c : str)
            c = toupper(c);

    for (std::string::size_type i = 0; i != strWord.size(); i++)
    {
        if (i != 0 && i % 8 == 0)
            std::cout << std::endl;
        std::cout << strWord[i] << "\n";
    }
    std::cout << std::endl;

    system("pause");
    return 0;
}
