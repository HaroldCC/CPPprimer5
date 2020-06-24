/*************************************************************************
> File Name       : 12.28.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月22日  20时54分53秒
************************************************************************/
#include <iostream>
using std::cin, std::cout, std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <memory>
using std::shared_ptr, std::make_shared;
#include <fstream>
using std::ifstream;
#include <sstream>
#include <map>
using std::map;
#include <set>
using std::set;
#include <algorithm>
using std::remove_copy_if;
#include <iterator>
using std::back_inserter;

int main(int argc, const char *argv[])
{
    ifstream infile("12.27/storyDataFile.txt");
    vector<string> input;
    map<string, set<decltype(input.size())>> dictionary;
    decltype(input.size()) lineNum = 0;

    for (string line; std::getline(infile, line); ++lineNum)
    {
        input.push_back(line);
        std::istringstream lineStream(line);
        for (string text, word; lineStream >> text; word.clear())
        {
            remove_copy_if(text.begin(), text.end(), back_inserter(word), ispunct);
            dictionary[word].insert(lineNum);
        }
    }

    while (true)
    {
        cout << "enter a word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")
            break;
        auto found = dictionary.find(s);
        if (found != dictionary.end())
        {
            cout << s << " occurs " << found->second.size() << (found->second.size() > 1 ? " times" : " time") << endl;
            for (auto i : found->second)
                cout << "\t(line " << i + 1 << ") " << input.at(i) << endl;
        }
    }

    system("pause");
    return 0;
}