/*************************************************************************
> File Name       : 11.7.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月15日  12时18分52秒
************************************************************************/
#include <iostream>
using std::cin, std::cout, std::endl;
#include <map>
using std::map;
#include <string>
using std::string;
#include <vector>
using std::vector;

int main(int argc, const char *argv[])
{
    map<string, vector<string>> familyMember;

    for (string lastName; cout << "Last name: ", cin >> lastName && lastName != "@q";)
        for (string childrensName; cout << "Children's name: ", cin >> childrensName && childrensName != "@q";)
            familyMember[lastName].push_back(childrensName);

    system("pause");
    return 0;
}