/*************************************************************************
> File Name       : 9.27.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月10日  17时40分14秒
************************************************************************/
#include <iostream>
#include <forward_list>

int main(int argc, char const *argv[])
{
    std::forward_list<int> ifl{0, 1, 2, 3, 4, 5, 6, 7};
    auto prev = ifl.before_begin();
    auto curr = ifl.begin();

    while (curr != ifl.end())
    {
        if (*curr & 1)
        {
            curr = ifl.erase_after(prev);
        }
        else
        {
            prev = curr;
            ++curr;
        }
    }

    for (auto i : ifl)
        std::cout << i << " ";
    std::cout << std::endl;

    system("pause");
    return 0;
}