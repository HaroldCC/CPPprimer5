/*************************************************************************
> File Name       : 6.33.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月30日  22时25分45秒
************************************************************************/
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void print_vector(vector<int>::const_iterator beg, vector<int>::const_iterator end)
{
    if (beg == end)
    {
        cout << "over!" << std::endl;
        return;
    }
    cout << *beg << " ";
    print_vector(++beg, end);
}

int main(int argc, char const *argv[])
{
    vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    print_vector(vec.cbegin(), vec.cend());

    system("pause");
    return 0;
}