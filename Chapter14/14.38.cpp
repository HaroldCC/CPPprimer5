/*************************************************************************
> File Name       : 14.38.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月28日  07时13分21秒
************************************************************************/
#include <string>
using std::string;
#include <iostream>
#include <fstream>
using std::ifstream;

class BoundTest
{
private:
    size_t m_lower;
    size_t m_upper;

public:
    BoundTest(size_t l = 0, size_t u = 0) : m_lower(l), m_upper(u) {}
    bool operator()(const std::string &str) { return str.size() >= m_lower && str.size() <= m_upper; }
};

int main(int argc, const char *argv[])
{
    ifstream filein("14.38.cpp");

    if (!filein)
        std::cerr << "can't open the file." << std::endl;

    size_t count1, count2, count10, count1_9, count10_up;
    count1 = count2 = count10 = count1_9 = count10_up = 0;

    BoundTest test1(0, 1);
    BoundTest test2(1, 2);
    BoundTest test10(9, 10);
    BoundTest test1_9(1, 9);
    BoundTest test10_up(10, 20);

    for (string word; filein >> word;)
    {
        if (test1(word))
            ++count1;
        if (test2(word))
            ++count2;

        if (test1_9(word))
            ++count1_9;

        if (test10_up(word))
            ++count10_up;
    }

    std::cout << count1 << " " << count2 << " " << count10 << " " << count1_9 << " " << count10_up << std::endl;

    system("pause");
    return 0;
}