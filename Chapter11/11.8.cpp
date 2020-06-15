/*************************************************************************
> File Name       : 11.8.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月15日  12时42分18秒
************************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <algorithm>
using std::binary_search;

int main(int argc, const char *argv[])
{
    vector<string> words{"aa", "bb", "cc", "hello", "world"};

    for (string newWord; cout << "input a new word: ", cin >> newWord;)
    {
        auto isExcluded = binary_search(words.cbegin(), words.cend(), newWord);
        cout << (isExcluded ? "excluded." : "not excluded.") << endl;
    }

    for (auto i : words)
        cout << i << " ";
    cout << endl;

    system("pause");
    return 0;
}