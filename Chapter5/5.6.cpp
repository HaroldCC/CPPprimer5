/*************************************************************************
    > File Name       : 5.6.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 20/5/25 12:25:58
 ************************************************************************/
#include<iostream>
#include <vector>
#include <string>

int main(int argc,char *argv[])
{
	std::vector<std::string> scores = {"F", "D", "C", "B", "A", "A++"};

	int grade = 0;
	while (std::cin >> grade)
	{
		std::string letterGrade = grade < 60 ? scores[0] : scores[(grade - 50) / 10];
		letterGrade += (grade == 100 || grade < 60) ? "" :(grade % 10 > 7) ? "+" : (grade % 10 < 3) ? "-" : "";
		std::cout << letterGrade << std::endl;
	}
     
    return 0;
}

