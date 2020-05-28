/*************************************************************************
    > File Name       : 5.5.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 20/5/25 12:09:46
 ************************************************************************/
#include<iostream>
#include <vector>
#include <string>

int main(int argc,char *argv[])
{
	const std::vector<std::string> scores = {"F", "D", "C", "B", "A", "A++"};
	for(int g; std::cin >> g ;/*&& g != 'q'; std::cin.get()*/)
	{
		std::string letterGrade;
		if(g < 60)
			letterGrade = scores[0];
		else
		{
			letterGrade = scores[(g - 50) / 10];
			if(g != 100)
				letterGrade += g % 10 > 7 ? "+" : g % 10 < 3 ? "-" : "";
		}
		std::cout << letterGrade << std::endl;
	} 
    return 0;
}

