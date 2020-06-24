/*************************************************************************
> File Name       : 12.24.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月22日  10时09分43秒
************************************************************************/
#include <iostream>
#include <cstring>

int main(int argc, const char *argv[])
{
    std::cout << "input the size of the string: ";
    int size = 0;
    std::cin >> size;

    char *input = new char[size + 1]();

    std::cin.ignore(); // 清除上一次输入留下的回车符

    std::cout << "input the string: ";
    std::cin.get(input, size + 1);
    std::cout << input;
    std::cout << std::endl;

    delete[] input;

    system("pause");
    return 0;
}