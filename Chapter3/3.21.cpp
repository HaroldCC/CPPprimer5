/*************************************************************************
> File Name       : 3.21.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月11日  17时37分36秒
************************************************************************/
#include <iostream>
#include <vector>
#include <string>

void check_and_print(const std::vector<int> &vec)
{
    std::cout << "size: " << vec.size() << " value: [";
    for (auto it = vec.cbegin(); it != vec.cend(); it++)
        std::cout << *it << (it != vec.end() - 1 ? "," : "");
    std::cout << "]\n"
              << std::endl;
}

void check_and_print(const std::vector<std::string> &vec)
{
    std::cout << "size: " << vec.size() << " value: [";
    for (auto it = vec.cbegin(); it != vec.cend(); it++)
        std::cout << *it << (it != vec.cend() - 1 ? "," : "");
    std::cout << "]\n"
              << std::endl;
}

int main(int argc, char const *argv[])
{
    std::vector<int> v1;
    std::vector<int> v2(10);
    std::vector<int> v3(10, 42);
    std::vector<int> v4{10};
    std::vector<int> v5{10, 42};
    std::vector<std::string> v6{10};
    std::vector<std::string> v7{10, "hi"};

    check_and_print(v1);
    check_and_print(v2);
    check_and_print(v3);
    check_and_print(v4);
    check_and_print(v5);
    check_and_print(v6);
    check_and_print(v7);

    system("pause");
    return 0;
}
