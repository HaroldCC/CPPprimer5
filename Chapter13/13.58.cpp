/*************************************************************************
> File Name       : 13.58.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月26日  11时00分54秒
************************************************************************/
#include <vector>
#include <algorithm>
#include <iostream>

class Foo
{
private:
    std::vector<int> m_data;

public:
    Foo sorted() &&;
    Foo sorted() const &;
};
Foo Foo::sorted() &&
{
    std::sort(m_data.begin(), m_data.end());
    std::cout << "&&" << std::endl;
    return *this;
}

Foo Foo::sorted() const &
{
    std::cout << "const &" << std::endl;
    return Foo(*this).sorted();
}

#include <iostream>

int main(int argc, const char *argv[])
{
    Foo().sorted(); // 右值版本

    Foo f;
    f.sorted(); // 左值版本

    system("pause");
    return 0;
}
