/*************************************************************************
    > File Name       : 5.9.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 20/5/25 12:33:45
 ************************************************************************/
#include<iostream>

int main(int argc,char *argv[])
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, uCnt = 0;
	char ch;
	while (std::cin >> ch && ch != '@')
	{
		if(ch == 'a') ++aCnt;
		else if(ch == 'e') ++eCnt;
		else if(ch == 'i') ++iCnt;
		else if(ch == 'u') ++uCnt;
	}

	std::cout << "Number of vowel a: \t" << aCnt << std::endl;
	std::cout << "Number of vowel e: \t" << eCnt << std::endl;
	std::cout << "Number of vowel i: \t" << iCnt << std::endl;
	std::cout << "Number of vowel u: \t" << uCnt << std::endl;
     
    return 0;
}

