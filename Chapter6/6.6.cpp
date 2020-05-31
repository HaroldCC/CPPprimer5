/*************************************************************************
> File Name       : 6.6.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月30日  15时19分37秒
************************************************************************/
#include <iostream>

void sample(int value) // value是形参
{
    int num = value + 1;           // num是局部变量
    static unsigned call_time = 0; // call_time 是局部静态变量
    std::cout << "value : " << value << " call sample " << ++call_time << " times" << std::endl;
}

int main(int argc, char const *argv[])
{
    for (size_t i = 0; i < 10; i++) // i 也是局部变量
    {
        sample(i);
    }

    system("pause");
    return 0;
}