/*************************************************************************
> File Name       : 9.20.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月10日  14时30分21秒
************************************************************************/
#include <iostream>
#include <list>
#include <deque>

int main(int argc, char const *argv[])
{
    std::list<int> ilst{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::deque<int> odd, even;

#/* 法一： */
    // for (auto it = ilst.cbegin(); it != ilst.cend(); ++it)
    // {
    //     if (*it % 2)
    //         odd.push_back(*it);
    //     else
    //         even.push_back(*it);
    // }

    // for (auto it = odd.cbegin(); it != odd.cend(); ++it)
    // {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;

    // for (auto it = even.cbegin(); it != even.cend(); ++it)
    // {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;

#/* 法二： */
    for (auto i : ilst)
        (i % 2 ? odd : even).push_back(i);

    for (auto i : odd)
        std::cout << i << " ";

    std::cout << std::endl;

    for (auto i : even)
        std::cout << i << " ";

    system("pause");
    return 0;
}