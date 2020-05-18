/*************************************************************************
> File Name       : 3.16.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月11日  09时19分38秒
************************************************************************/
#include <iostream>
#include <vector>
#include <string>

int main(int argc, char const *argv[])
{
    std::vector<int> v1;
    std::cout << "{\n \"v1\":{\"size\":\"" << v1.size() << "\",\"value\":[";
    for (auto i : v1)
        std::cout << i << ",";
    if (!v1.empty())
        std::cout << "\b";
    std::cout << "]}" << std::endl;

    std::vector<int> v2(10);
    std::cout << " \"v2\":{\"size\":\"" << v2.size() << "\",\"value\":[";
    for (auto i : v2)
        std::cout << i << ",";
    if (!v2.empty())
        std::cout << "\b";
    std::cout << "]}" << std::endl;

    std::vector<int> v3(10, 42);
    std::cout << " \"v3\":{\"size\":\"" << v3.size() << "\",\"value\":[";
    for (auto i : v3)
        std::cout << i << ",";
    if (!v3.empty())
        std::cout << "\b";
    std::cout << "]}" << std::endl;

    std::vector<int> v4{10};
    std::cout << " \"v4\":{\"size\":\"" << v4.size() << "\",\"value\":[";
    for (auto i : v4)
        std::cout << i << ",";
    if (!v4.empty())
        std::cout << "\b";
    std::cout << "]}" << std::endl;

    std::vector<int> v5{10, 42};
    std::cout << " \"v5\":{\"size\":\"" << v5.size() << "\",\"value\":[";
    for (auto i : v5)
        std::cout << i << ",";
    if (!v5.empty())
        std::cout << "\b";
    std::cout << "]}" << std::endl;

    std::vector<std::string> v6{10};
    std::cout << " \"v6\":{\"size\":\"" << v6.size() << "\",\"value\":[";
    for (auto i : v6)
        if (i.empty())
            std::cout << "(null)"
                      << ",";
        else
            std::cout << i << ",";
    if (!v6.empty())
        std::cout << "\b";
    std::cout << "]}" << std::endl;

    std::vector<std::string> v7{10, "hi"};
    std::cout << " \"v7\":{\"size\":\"" << v7.size() << "\",\"value\":[";
    for (auto i : v7)
        if (i.empty())
            std::cout << "(null)"
                      << ",";
        else
            std::cout << i << ",";
    if (!v7.empty())
        std::cout << "\b";
    std::cout << "]}" << std::endl;
    std::cout << "}" << std::endl;

    system("pause");
    return 0;
}
