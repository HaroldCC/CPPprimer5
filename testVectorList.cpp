/*************************************************************************
> File Name       : testVectorList.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月26日  23时28分43秒
************************************************************************/
#include <iostream>
#include "vectorList.h"

int main(int argc, const char *argv[])
{
    VectorList<int> vlst;
    vlst.insert_val(2, 1);
    vlst.insert_val(4, 2);
    vlst.insert_val(1, 3);
    vlst.insert_val(9, 4);
    vlst.insert_val(1, 3);
    vlst.insert_val(3, 6);

    std::cout << "after inset " << vlst << std::endl;

    vlst.insert_val(100, 2);
    std::cout << "place 2 insert 100 " << vlst << std::endl;

    int m;
    vlst.delete_val(m, 2);
    std::cout << "index 2 value = " << m << std::endl;
    std::cout << "after delete " << vlst << std::endl;

    int index = vlst.find(9);
    std::cout << "the value 9's index = " << index << std::endl;

    index = vlst.find(6);
    std::cout << "the value 6's index = " << index << std::endl;

    system("pause");
    return 0;
}