/*************************************************************************
> File Name       : 12.27.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月22日  19时22分25秒
************************************************************************/
#include <iostream>
using std::cout, std::endl;
#include <fstream>
using std::ifstream;
#include "12.27.h"
#include <string>
using std::string;

void run_queries(ifstream &input)
{
    TextQuery tq(input);
    while (true)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(std::cin >> s) || s == "q")
            break;
        print(cout, tq.query(s)) << endl;
    }
}

int main(int argc, const char *argv[])
{
    ifstream input("storyDataFile.txt");
    run_queries(input);

    system("pause");
    return 0;
}