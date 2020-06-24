/*************************************************************************
> File Name       : 12.27.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月22日  10时36分01秒
************************************************************************/
#ifndef EX12_27_H
#define EX12_27_H

#include <memory>
using std::shared_ptr, std::make_shared;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <map>
using std::map;
#include <set>
using std::set;
#include <fstream>
using std::ifstream;
#include <sstream>
#include <string>

class QueryResult;

class TextQuery
{
public:
    using lineNum = vector<string>::size_type;

private:
    shared_ptr<vector<string>> m_file;
    map<string, shared_ptr<set<lineNum>>> m_word;

public:
    TextQuery(ifstream &input);
    QueryResult query(const string &str) const;
};

class QueryResult
{
private:
    string m_sought;
    shared_ptr<set<TextQuery::lineNum>> m_lines;
    shared_ptr<vector<string>> m_file;

public:
    friend std::ostream &print(std::ostream &out, const QueryResult &theQueryResult);

    QueryResult(string s, shared_ptr<set<TextQuery::lineNum>> p,
                shared_ptr<vector<string>> f) : m_sought(s), m_lines(p), m_file(f) {}
};

TextQuery::TextQuery(ifstream &input) : m_file(new vector<string>)
{
    string text;
    while (std::getline(input, text))
    {
        m_file->push_back(text);
        int n = m_file->size() - 1;
        std::istringstream line(text);
        string word;
        while (line >> word)
        {
            auto &lines = m_word[word];
            if (!lines)
                lines.reset(new set<lineNum>);
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string &str) const
{
    static shared_ptr<set<lineNum>> nodata(new set<lineNum>);
    auto loc = m_word.find(str);
    if (loc == m_word.end())
        return QueryResult(str, nodata, m_file);
    else
        return QueryResult(str, loc->second, m_file);
}

std::ostream &print(std::ostream &out, const QueryResult &theQueryResult)
{
    out << theQueryResult.m_sought << " occurs " << theQueryResult.m_lines->size() << " "
        << "time" << (theQueryResult.m_lines->size() > 1 ? "s" : " ") << endl;

    for (auto num : *theQueryResult.m_lines)
        out << "\t(line " << num + 1 << ")" << *(theQueryResult.m_file->begin() + num) << endl;
    return out;
}
#endif // !EX12_27_H
