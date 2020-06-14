/*************************************************************************
> File Name       : 10.30.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月14日  10时18分03秒
************************************************************************/
#include <iostream>
using std::cout, std::endl;
#include <algorithm>
using std::sort, std::copy;
#include <iterator>
using std::istream_iterator, std::ostream_iterator;
#include <vector>
using std::vector;

int main(int argc, const char *argv[])
{
    vector<int> ivec;

    istream_iterator<int> int_it(std::cin), int_eof;

    copy(int_it, int_eof, std::back_inserter(ivec));
    sort(ivec.begin(), ivec.end());

    copy(ivec.cbegin(), ivec.cend(), ostream_iterator<int>(cout, " "));

    system("pause");
    return 0;
}