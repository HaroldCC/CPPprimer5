/*************************************************************************
> File Name       : 8.11.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月07日  22时25分38秒
************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

struct PersonInfo
{
    std::string name;
    std::vector<std::string> phone;
};

int main(int argc, char const *argv[])
{
    std::string line, word;
    std::vector<PersonInfo> people;

    std::istringstream record;

    while (std::getline(std::cin, line))
    {
        PersonInfo info;

        record.clear();

        record.str(line);

        record >> info.name;

        while (record >> word)
            info.phone.push_back(word);
        people.push_back(info);
    }

    for (auto &s : people)
    {
        std::cout << s.name << " ";
        for (auto &p : s.phone)
            std::cout << p << " ";
        std::cout << std::endl;
    }

    system("pause");
    return 0;
}