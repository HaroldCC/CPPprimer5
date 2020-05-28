/*************************************************************************
    > File Name       : 5.24.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2020/05/28 9:11:29
 ************************************************************************/
#include<iostream>
#include <stdexcept>

int main(int argc,char *argv[])
{
	int num1, num2;
	std::cin >> num1 >> num2;
	if(num2 == 0)
		throw std::runtime_error("divisor is 0");
	std::cout << num1 / num2 << std::endl;
     
    return 0;
}

