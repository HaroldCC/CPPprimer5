/*************************************************************************
> File Name       : 9.44.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月10日  20时55分58秒
************************************************************************/
#include <iostream>
#include <string>

void replace_strings(std::string &str, const std::string &oldVal, const std::string &newVal)
{
    for (size_t pos = 0; pos <= str.size() - oldVal.size(); ++pos)
    {
        if (str[pos] == oldVal[0] && str.substr(pos, oldVal.size()) == oldVal)
        {
            str.replace(pos, oldVal.size(), newVal);
            pos += newVal.size();
        }
    }
}

int main(int argc, char const *argv[])
{
    std::string str{"thu is thu, thru is thru."};

    replace_strings(str, "thu", "though");
    replace_strings(str, "thru", "through");

    std::cout << str << std::endl;

    system("pause");
    return 0;
}