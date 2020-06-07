/*************************************************************************
> File Name       : 8.5.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月07日  13时29分51秒
************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void readfile(const std::string &fileName, std::vector<std::string> &fileContent)
{

    std::ifstream fin(fileName);
    if (fin)
    {
        std::string contentLine;
        while (fin >> contentLine)
        {
            fileContent.push_back(contentLine);
        }
    }
    else
        std::cerr << "couldn't open: " + fileName;
}

int main(int argc, char const *argv[])
{

    system("pause");
    return 0;
}