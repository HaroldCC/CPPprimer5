/*************************************************************************
> File Name       : 12.7.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月21日  15时36分24秒
************************************************************************/
#include <iostream>
using std::cin, std::cout, std::endl;
#include <memory>
using std::make_shared, std::shared_ptr;
#include <vector>
using std::vector;

shared_ptr<vector<int>> dynamic_allocation_use_shared_ptr()
{
    return make_shared<vector<int>>();
}

void assign_vector(shared_ptr<vector<int>> p)
{
    int num;
    while (cin >> num)
    {
        p->push_back(num);
    }
}

int main(int argc, const char *argv[])
{
    auto p = dynamic_allocation_use_shared_ptr();
    assign_vector(p);
    for (auto i : *p)
        cout << i << " ";
    cout << endl;

    system("pause");
    return 0;
}