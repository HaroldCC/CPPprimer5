/*************************************************************************
> File Name       : 16.63.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年07月02日  15时47分53秒
************************************************************************/
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;

template <typename T>
size_t find_number(T t, const vector<T> &vt)
{
    size_t occurrences = 0;

    for (auto it = vt.cbegin(); it != vt.cend(); ++it)
    {
        if (*it == t)
            break;
        ++occurrences;
    }

    return occurrences;
}

size_t find_number(const char *t, const vector<string> &vt)
{
    size_t occurrences = 0;
    string s(t);

    for (auto it = vt.cbegin(); it != vt.cend(); ++it)
    {
        if (*it == t)
            break;
        ++occurrences;
    }

    return occurrences;
}

template <>
size_t find_number(const char *t, const vector<const char *> &vt)
{
    size_t occurrences = 0;

    for (auto it = vt.cbegin(); it != vt.cend(); ++it)
    {
        if (*it == t)
            break;
        ++occurrences;
    }

    return occurrences;
}

int main(int argc, const char *argv[])
{
    vector<int> vi = {1, 2, 3, 3, 4, 3, 5, 6};
    vector<double> vd = {1, 2, 3, 3.14, 4, 3.14, 5, 6.28};
    vector<string> vs = {"a", "bb", "ccc", "dddd"};
    vector<const char *> vcp = {"a", "bb", "ccc", "dddd"};

    cout << find_number(3.14, vd) << endl;
    cout << find_number(3, vi) << endl;
    cout << find_number("bb", vs) << endl;
    cout << find_number("ccc", vcp) << endl;

    system("pause");
    return 0;
}