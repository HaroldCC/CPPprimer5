/*************************************************************************
> File Name       : 9.43.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月10日  19时12分14秒
************************************************************************/
#include <iostream>
#include <string>

void change_string(std::string &str, const std::string &oldVal, const std::string &newVal)
{
    auto curr = str.begin();
    while (curr != str.end() - oldVal.size())
    {
        if (oldVal == std::string(curr, curr + oldVal.size()))
        {
            curr = str.erase(curr, curr + oldVal.size());
            curr = str.insert(curr, newVal.begin(), newVal.end());
            curr += newVal.size();
        }
        else
            ++curr;
    }
}

int main(int argc, char const *argv[])
{

    std::string str("tho is tho, thru is thru. dou you ");

    change_string(str, "tho", "though");
    change_string(str, "thru", "through");

    std::cout << str << std::endl;

    system("pause");
    return 0;
}