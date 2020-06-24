/*************************************************************************
> File Name       : 12.6.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月21日  15时25分30秒
************************************************************************/
#include <iostream>
using std::cin, std::cout, std::endl;
#include <vector>
using std::vector;

vector<int> *dynamic_allocation_use_new()
{
    return new vector<int>();
}

void assign_vector(vector<int> *p)
{
    int num;
    while (cin >> num)
    {
        p->push_back(num);
    }
}

int main(int argc, const char *argv[])
{
    auto p = dynamic_allocation_use_new();
    assign_vector(p);

    for (auto i : *p)
        cout << i << " ";
    cout << endl;
    delete p;

    system("pause");
    return 0;
}