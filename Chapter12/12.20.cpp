/*************************************************************************
> File Name       : 12.20.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月21日  19时40分35秒
************************************************************************/
#include <iostream>
#include <fstream>
#include "12.19.h"

int main(int argc, const char *argv[])
{
    std::ifstream finput("12.20.txt");
    StrBlob sb;

    std::string s;
    while (std::getline(finput, s))
    {
        sb.push_back(s);
    }

    for (StrBlobPtr sbp = sb.begin(); sbp != sb.end(); sbp.incr())
    {
        std::cout << sbp.deref() << std::endl;
    }

    system("pause");
    return 0;
}