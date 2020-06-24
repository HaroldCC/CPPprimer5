/*************************************************************************
> File Name       : 12.26.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月22日  10时26分44秒
************************************************************************/
#include <iostream>
#include <string>
#include <memory>

int main(int argc, const char *argv[])
{
    int n = 10;
    std::allocator<std::string> alloc;
    auto const p = alloc.allocate(n);
    auto q = p;
    std::string str;
    while (std::cin >> str && q != p + n)
    {
        alloc.construct(q++, str);
    }

    while (q != p)
    {
        std::cout << *--q << " ";
        alloc.destroy(q);
    }

    alloc.deallocate(p, n);

    system("pause");
    return 0;
}