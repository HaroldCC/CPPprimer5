/*************************************************************************
> File Name       : 3.42.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月18日  14时57分58秒
************************************************************************/
#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<int> vec{0, 1, 2, 3, 4, 5};
    int array[6];
    for (int i = 0; i != vec.size(); i++)
        array[i] = vec[i];

    for (auto i : array)
        std::cout << i << " ";
    std::cout << std::endl;

    system("pause");
    return 0;
}
