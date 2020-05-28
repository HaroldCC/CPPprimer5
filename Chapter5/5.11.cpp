/*************************************************************************
    > File Name       : 5.11.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 20/5/25 14:51:22
 ************************************************************************/
#include<iostream>

int main(int argc,char *argv[])
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, sCnt = 0, tCnt = 0, nCnt = 0;
	char ch;

	while (std::cin >> std::noskipws >> ch && ch != '@')
		switch (ch)
		{
			case 'a':
			case 'A': ++aCnt; break;
			case 'e':
			case 'E': ++eCnt; break;
			case 'i':
			case 'I': ++iCnt; break;
			case 'o':
			case 'O': ++oCnt; break;
			case 'u':
			case 'U': ++uCnt; break;
			case ' ': ++sCnt; break;
			case '\t': ++tCnt; break;
			case '\n': ++nCnt; break;
		}
     
	std::cout << "Number of vowel a(A): \t" << aCnt << std::endl;
	std::cout << "Number of vowel e(E): \t" << eCnt << std::endl;
	std::cout << "Number of vowel i(I): \t" << iCnt << std::endl;
	std::cout << "Number of vowel o(O): \t" << oCnt << std::endl;
	std::cout << "Number of vowel u(U): \t" << uCnt << std::endl;
	std::cout << "Number of space: \t" << sCnt << std::endl;
	std::cout << "Number of tab: \t" << tCnt << std::endl;
	std::cout << "Number of new line: \t" << nCnt << std::endl;
     
    return 0;
}

