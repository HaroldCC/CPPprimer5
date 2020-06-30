/*************************************************************************
> File Name       : testString.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月30日  15时04分15秒
************************************************************************/
#include <iostream>
#include <string>
using std::string, std::wstring;
#include "String.h"

int main(int argc, const char *argv[])
{
    string str_a = "你好123";
    wstring str_w = L"哈哈456";

    string str_dst_a = String::to_astring(str_w);
    wstring str_dst_w = String::a2w_string(str_a);

    system("pause");
    return 0;
}