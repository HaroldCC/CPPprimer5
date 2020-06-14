/*************************************************************************
> File Name       : 10.33.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月14日  10时38分34秒
************************************************************************/
#include <iostream>
using std::cout, std::endl;
#include <fstream>
using std::ifstream, std::ofstream;
#include <iterator>
using std::istream_iterator, std::ostream_iterator;
#include <algorithm>
using std::for_each;

int main(int argc, const char *argv[])
{
    if (argc != 4)
        return -1;

    ifstream finput(argv[1]);
    ofstream foutputOdd(argv[2]), foutputEven(argv[3]);

    istream_iterator<int> in(finput), eof;
    ostream_iterator<int> outOdd(foutputOdd, " "), outEven(foutputEven, "\n");

    for_each(in, eof,
             [&outOdd, &outEven](const int i) { *(i & 0x1 ? outOdd : outEven)++ = i; });

    system("pause");
    return 0;
}