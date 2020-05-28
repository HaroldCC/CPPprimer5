/*************************************************************************
    > File Name       : 5.12.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 20/5/25 17:52:52
 ************************************************************************/
#include<iostream>

int main(int argc,char *argv[])
{	
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0,
			 uCnt = 0, sCnt = 0, tCnt = 0, nCnt = 0,
			 ffCnt = 0, flCnt = 0, fiCnt = 0;
	char ch, prech = '\0';

	while (std::cin >> std::noskipws >> ch && ch != '@')
	{
		switch (ch)
		{
			case 'a':
			case 'A': ++aCnt; break;
			case 'e':
			case 'E': ++eCnt; break;
			case 'i': if(prech == 'f') ++fiCnt; break;
			case 'I': ++iCnt; break;
			case 'o':
			case 'O': ++oCnt; break;
			case 'u':
			case 'U': ++uCnt; break;
			case ' ': ++sCnt; break;
			case '\t': ++tCnt; break;
			case '\n': ++nCnt; break;
			case 'f': if(prech == 'f') ++ffCnt; break;
			case 'l': if(prech == 'f') ++flCnt; break;
		}
		prech = ch;
	}
     
	std::cout << "Number of vowel a(A): \t" << aCnt << std::endl;
	std::cout << "Number of vowel e(E): \t" << eCnt << std::endl;
	std::cout << "Number of vowel i(I): \t" << iCnt << std::endl;
	std::cout << "Number of vowel o(O): \t" << oCnt << std::endl;
	std::cout << "Number of vowel u(U): \t" << uCnt << std::endl;
	std::cout << "Number of space: \t" << sCnt << std::endl;
	std::cout << "Number of tab: \t" << tCnt << std::endl;
	std::cout << "Number of ff: \t" << ffCnt << std::endl;
	std::cout << "Number of fl: \t" << flCnt << std::endl;
	std::cout << "Number of fi: \t" << fiCnt << std::endl;
 
     
    return 0;
}

