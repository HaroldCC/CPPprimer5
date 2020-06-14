/*************************************************************************
> File Name       : 9.26.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月10日  16时23分11秒
************************************************************************/
#include <iostream>
#include <vector>
#include <list>

int main(int argc, char const *argv[])
{
    int ia[] = {0, 1, 1, 2, 3, 5, 6, 13, 21, 55, 89};

    std::vector<int> ivec(ia, std::end(ia));
    std::list<int> ilst(ia, std::end(ia));

        for (auto i : ivec)
        std::cout << i << " ";
    std::cout << std::endl;

    for (auto i : ilst)
        std::cout << i << " ";
    std::cout << std::endl;

    std::vector<int> vec(ia, std::end(ia));
    std::list<int> lst(vec.begin(), vec.end());

    for (auto it = lst.begin(); it != lst.end();)
        if (*it & 0x1)
            it = lst.erase(it);
        else
            ++it;

    for (auto it = vec.begin(); it != vec.end();)
        if (!(*it & 0x1))
            it = vec.erase(it);
        else
            ++it;

    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;

    for (auto i : lst)
        std::cout << i << " ";
    std::cout << std::endl;

    system("pause");
    return 0;
}