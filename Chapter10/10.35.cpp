/*************************************************************************
> File Name       : 10.35.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月14日  17时24分46秒
************************************************************************/
#include <iostream>
using std::cout, std::endl;
#include <vector>
using std::vector;

int main(int argc, const char *argv[])
{
    vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto it = ivec.cend(); it != ivec.cbegin(); --it)
    {
        cout << *(it - 1) << " "; // 由于ivec.cend()返回最后元素的后一个迭代器，因此输出结果时要后退一位
    }
    cout << endl;

    system("pause");
    return 0;
}