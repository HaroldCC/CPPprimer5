#include <iostream>
#include <string>
#include <fstream>

void find_not_in(const std::string &s, std::string &result)
{
    std::string notIn("dfpg");
    int size;
    if (s.find_first_of(notIn) == std::string::npos)
        result = result.size() < s.size() ? s : result;
}

int main(int argc, char const *argv[])
{
    std::ifstream input("D:/studySpace/CppPrimer5/Chapter9/9.49.cpp");
    if (!input)
        return -1;

    std::string longest;

    for (std::string curr; input >> curr;)
    {
        find_not_in(curr, longest);
    }
    std::cout << longest << std::endl;

    system("pause");
    return 0;
}