/*************************************************************************
> File Name       : 8.10.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月07日  22时12分59秒
************************************************************************/
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>

int main(int argc, char const *argv[])
{
    std::ifstream input("./test8.10.txt");
    if (!input)
    {
        std::cerr << "couldn't open file! " << std::endl;
        return -1;
    }

    std::vector<std::string> vecStrLine;
    std::string line;
    while (std::getline(input, line))
    {
        vecStrLine.push_back(line);
    }

    for (auto &s : vecStrLine)
    {
        std::istringstream iss(s);
        std::string word;
        while (iss >> word)
        {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }

    system("pause");
    return 0;
}