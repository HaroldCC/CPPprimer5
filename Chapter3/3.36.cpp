/*************************************************************************
> File Name       : 3.36.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月18日  10时34分46秒
************************************************************************/
#include <iostream>
#include <vector>

bool compare(int *const pb1, int *const pe1, int *const pb2, int *const pe2)
{
    if ((pe1 - pb1) != (pe2 - pb2)) // 数组长度不同
    {
        return false;
    }
    else
    {
        for (int *i = pb1, *j = pb2; (i != pe1) && (j != pe2); i++, j++)
        {
            if (*i != *j) // 相同位置值不同
                return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int array1[] = {0, 1, 2, 3};
    int array2[] = {0, 1, 2, 3};
    int array3[] = {1, 2, 3, 4};

    if (compare(std::begin(array1), std::end(array1), std::begin(array2), std::end(array2)))
        std::cout << "array1 are equles array2." << std::endl;
    else
        std::cout << "array1 are not equles array2." << std::endl;

    if (compare(std::begin(array1), std::end(array1), std::begin(array3), std::end(array3)))
        std::cout << "array1 are equles array3." << std::endl;
    else
        std::cout << "array1 are not equles array3." << std::endl;

    std::vector<int> vec1 = {0, 1, 2};
    std::vector<int> vec2 = {0, 1, 2};

    if (vec1 == vec2)
        std::cout << "vec1 are equles vec2." << std::endl;
    else
        std::cout << "vec1 are not equles vec2." << std::endl;

    system("pause");
    return 0;
}
