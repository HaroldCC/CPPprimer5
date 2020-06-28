/*************************************************************************
> File Name       : 14.37.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月27日  21时42分30秒
************************************************************************/
#include <iostream>
using std::cin, std::cout, std::endl;
#include <algorithm>
#include <vector>
using std::vector;

class IsEqual
{
    int m_value;

public:
    IsEqual(int val) : m_value(val) {}
    bool operator()(int val) { return m_value == val; }
};

int main(int argc, const char *argv[])
{
    vector<int> ivec{3, 4, 5, 9, 3, 7, 6, 5, 3, 2};

    std::replace_if(ivec.begin(), ivec.end(), IsEqual(3), 5);

    for (int i : ivec)
        cout << i << " ";
    cout << endl;

    system("pause");
    return 0;
}