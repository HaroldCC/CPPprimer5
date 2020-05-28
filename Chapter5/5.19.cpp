/*************************************************************************
    > File Name       : 5.19.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2020/05/27 20:21:59
 ************************************************************************/
#include<iostream>
#include <string>

int main(int argc,char *argv[])
{
	std::string is_continue;
	do{
		std::cout << "enter two strings: \n";
		std::string str1, str2;

		std::cin >> str1 >> str2;
		std::cout << (str1 > str2 ? str2 : str1) << "\n\n"
				  << "more? yes or no";
		std::cin >> is_continue;
	}while (is_continue != "no");
     
    return 0;
}

