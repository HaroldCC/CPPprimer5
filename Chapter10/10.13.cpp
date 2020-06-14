#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool isShorter(const std::string &lhs, int sz = 3)
{
    return lhs.size() > sz;
}

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type)
{
}

int main(int argc, char const *argv[])
{
    // std::vector<std::string> svec{"str", "strin", "str", "str", "str"};

    // auto i = std::find_if(svec.begin(), svec.end(), [](const std::string &lhs, const std::string str = "strin") { return lhs == str; });

    std::cout << "n:" << [](int x, int y = 4) { return x + y; }(5) << std::endl;

    system("pause");
    return 0;
}