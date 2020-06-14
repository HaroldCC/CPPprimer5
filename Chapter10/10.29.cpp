/*************************************************************************
> File Name       : 10.29.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月14日  10时07分08秒
************************************************************************/
#include <iostream>
using std::cout, std::endl;
#include <fstream>
using std::ifstream;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iterator>
using std::istream_iterator;

int main(int argc, const char *argv[])
{
    ifstream finput("10.29.txt");
    if (!finput)
        std::cerr << "can't open file!" << endl;

    istream_iterator<string> in(finput), eof;

    vector<string> svec;

    std::copy(in, eof, std::back_inserter(svec));

    std::copy(svec.cbegin(), svec.cend(), std::ostream_iterator<string>(cout, "\n"));

    system("pause");
    return 0;
}