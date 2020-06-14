#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool five_more_characters(const std::string &lhs)
{
    return lhs.size() >= 5;
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> svec{"string", "hello", "str", "world", "hell"};

    auto endFive = std::partition(svec.begin(), svec.end(), five_more_characters);

    for (auto it = svec.cbegin(); it != endFive; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    system("pause");
    return 0;
}