/*************************************************************************
> File Name       : 3.32.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月15日  08时15分16秒
************************************************************************/
#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    int array[10];
    for (int i = 0; i < 10; i++)
        array[i] = i;
    std::cout << "array: ";
    for (int i = 0; i < 10; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;

    int array2[10];
    for (int i = 0; i < 10; i++)
        array2[i] = array[i];
    std::cout << "array2: ";
    for (int i = 0; i < 10; i++)
        std::cout << array2[i] << " ";
    std::cout << std::endl;

    std::vector<int> vec1(10);
    for (int i = 0; i < 10; i++)
    {
        vec1[i] = array[i];
    }
    std::cout << "vec1: ";
    for (int i = 0; i < 10; i++)
    {
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;

    std::vector<int> vec2(vec1);
    // for (int i = 0; i < 10; i++)
    //     vec2[i] = vec1[i];
    std::cout << "vec2: ";
    for (int i = 0; i < 10; i++)
        std::cout << vec2[i] << " ";
    std::cout << std::endl;

    system("pause");
    return 0;
}
