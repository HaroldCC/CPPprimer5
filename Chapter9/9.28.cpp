/*************************************************************************
> File Name       : 9.28.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月10日  17时48分09秒
************************************************************************/
#include <iostream>
#include <forward_list>
#include <string>

void insert_string_to_forward_list(std::forward_list<std::string> &sfl, const std::string &str1, const std::string &str2)
{
    auto prev = sfl.before_begin();
    auto curr = sfl.begin();
    while (curr != sfl.end())
    {
        if (*curr == str1)
        {
            sfl.insert_after(curr, str2);
            return;
        }
        prev = curr;
        ++curr;
    }
    sfl.insert_after(prev, str2);
}

int main(int argc, char const *argv[])
{
    std::forward_list<std::string> sfl{"i", " am", "a", "coder"};

    insert_string_to_forward_list(sfl, "a", "m");

    insert_string_to_forward_list(sfl, "f", "end");

    for (auto i : sfl)
        std::cout << i << " ";
    std::cout << std::endl;

    system("pause");
    return 0;
}