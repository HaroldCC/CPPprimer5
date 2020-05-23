/*************************************************************************
> File Name       : 4.21.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月21日  09时43分08秒
************************************************************************/
#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // 这里使用布尔代数的“与”运算，判断一个数是奇数还是偶数
    for (auto i : vec)
        std::cout << ((i & 1) ? i * 2 : i) << " ";
    std::cout << std::endl;

    system("pause");
    return 0;
}
