/*************************************************************************
> File Name       : 3.41.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月18日  14时54分49秒
************************************************************************/
#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    int array[] = {0, 1, 2, 3, 4};

    std::vector<int> vec(std::begin(array), std::end(array));
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;

    system("pause");
    return 0;
}
