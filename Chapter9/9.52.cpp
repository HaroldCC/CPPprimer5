/*************************************************************************
> File Name       : 9.52.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月11日  09时12分31秒
************************************************************************/
#include <iostream>
#include <stack>

using namespace std;

string calc(string l, string r, string op)
{
    string s;
    if (op == "-")
        s = to_string(stoi(l) - stoi(r));
    return s;
}

int main(int argc, char const *argv[])
{
    string s("1+2*(7-4)");
    stack<string> stack;
    for (auto iter = s.begin(); iter != s.end();)
    {
        if (*iter == '(')
        {
            stack.push(string(1, *iter));
            ++iter;
            while (*iter != ')')
            {
                stack.push(string(1, *iter));
                ++iter;
            }
        }
        else if (*iter == ')')
        {
            string r = stack.top();
            stack.pop();
            string op = stack.top();
            stack.pop();
            string l = stack.top();
            stack.pop();
            stack.pop(); // '(' 弹出
            stack.push(calc(l, r, op));
            ++iter;
        }
        else
        {
            ++iter;
        }
    }

    while (!stack.empty())
    {
        cout << stack.top() << endl;
        stack.pop();
    }

    system("pause");
    return 0;
}