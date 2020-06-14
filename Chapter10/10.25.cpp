/*************************************************************************
> File Name       : 10.25.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月13日  20时56分09秒
************************************************************************/
#include <iostream>
using std::cout, std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <algorithm>
using std::stable_partition, std::sort, std::unique, std::for_each;
#include <functional>
using std::bind, std::placeholders::_1;

void eliminate_duplicate_words(vector<string> &words)
{
    sort(words.begin(), words.end());
    words.erase(unique(words.begin(), words.end()), words.end());
}

bool check_size(const string &str, string::size_type sz)
{
    return str.size() >= sz;
}

void greater_than_given_length_words(vector<string> &words, vector<string>::size_type sz)
{
    eliminate_duplicate_words(words);
    auto it = stable_partition(words.begin(), words.end(), bind(check_size, _1, sz));
    for_each(words.begin(), it, [](const string &str) { cout << str << " "; });
}

int main(int argc, const char *argv[])
{
    vector<string> svec{"hello", "hello world", "harold", "word", "hell"};

    greater_than_given_length_words(svec, 4);

    system("pause");
    return 0;
}