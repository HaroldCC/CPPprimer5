/*************************************************************************
> File Name       : 8.13.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月07日  22时46分22秒
************************************************************************/
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

struct PersonInfo
{
    std::string name;
    std::vector<std::string> phones;
};

bool valid(const std::string &str)
{
    return std::isdigit(str[0]);
}

std::string format(const std::string &str)
{
    return str.substr(0, 3) + "-" + str.substr(3, 3) + "-" + str.substr(6);
}

int main(int argc, char const *argv[])
{
    std::ifstream input("./test8.13.txt");
    if (!input)
    {
        std::cerr << "no data?!" << std::endl;
        return -1;
    }

    std::string line, word;
    std::vector<PersonInfo> people;
    std::istringstream record;
    while (std::getline(input, line))
    {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    for (const auto &entry : people)
    {
        std::ostringstream formatted, badNums;
        for (const auto &nums : entry.phones)
        {
            if (!valid(nums))
            {
                badNums << " " << nums;
            }
            else
            {
                formatted << " " << format(nums);
            }
        }
        if (badNums.str().empty())
            std::cout << entry.name << " " << formatted.str() << std::endl;
        else
            std::cerr << "input error: " << entry.name << " invalid number(s)" << badNums.str() << std::endl;
    }

    system("pause");
    return 0;
}
