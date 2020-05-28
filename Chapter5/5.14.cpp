/*************************************************************************
    > File Name       : 5.14.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2020/05/27 11:27:00
 ************************************************************************/
#include<iostream>
#include <string>

int main(int argc,char *argv[])
{
	std::pair<std::string, unsigned> maxDuplicated;
	unsigned repeatStrCnt = 0;
	for (std::string str, prevStr; std::cin >> str && str != "@"; prevStr = str)
	{
		if(str == prevStr) ++repeatStrCnt;
		else repeatStrCnt = 0;
		if(repeatStrCnt > maxDuplicated.second) maxDuplicated = {prevStr, repeatStrCnt};
	}

	if(maxDuplicated.first.empty()) std::cout << "There is no duplicated string." << std::endl;
	else std::cout << "the word " << maxDuplicated.first << " occurred " << maxDuplicated.second + 1 << " times." << std::endl;
     
    return 0;
}

