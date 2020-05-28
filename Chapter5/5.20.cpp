/*************************************************************************
    > File Name       : 5.20.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2020/05/27 20:14:16
 ************************************************************************/
#include<iostream>
#include <string>


int main(int argc,char *argv[])
{
	std::string str1, str2;
	while(std::cin >> str1 >> str2)
		if(str1 == str2)
			break;
		else 
			str2 = str1;

	if(std::cin.eof())
		std::cout << "done" << std::endl;
	else 
		std::cout << str1 << " occurs twice." << std::endl;
     
    return 0;
}

