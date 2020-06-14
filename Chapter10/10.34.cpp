/*************************************************************************
> File Name       : 10.34.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月14日  17时17分57秒
************************************************************************/
#include <iostream>
using std::cout, std::endl;
#include <vector>
using std::vector;

int main(int argc, const char *argv[])
{
    vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto it = ivec.crbegin(); it != ivec.crend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}