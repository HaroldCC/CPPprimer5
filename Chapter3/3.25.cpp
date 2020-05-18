/*************************************************************************
> File Name       : 3.25.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月12日  16时29分26秒
************************************************************************/
#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<unsigned> scores(11, 0);
    unsigned grade;

    while (std::cin >> grade)
    {
        if (grade <= 100)
            ++*(scores.begin() + grade / 10);
    }

    for (auto s : scores)
        std::cout << s << " ";
    std::cout << std::endl;

    system("pause");
    return 0;
}
