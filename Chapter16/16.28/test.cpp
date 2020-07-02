/*************************************************************************
> File Name       : test.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年07月01日  18时55分39秒
************************************************************************/
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "shared_ptr.h"
#include "unique_ptr.h"

int main(int argc, const char *argv[])
{
    auto foo = SharedPtr<int>(new int(42));
    auto bar(foo);
    cout << *foo << endl;
    cout << foo.use_count() << endl;

    auto stringPtr = SharedPtr<string>(new string("hello world"));
    cout << *stringPtr << endl;
    cout << stringPtr.use_count() << endl;

    auto foo2 = UniquePtr<int>(new int(42));
    cout << *foo2 << endl;

    auto stringPtr2 = UniquePtr<string>(new string("hello world"));
    cout << *stringPtr2 << endl;

    system("pause");
    return 0;
}