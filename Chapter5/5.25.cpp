/*************************************************************************
    > File Name       : 5.25.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2020/05/28 9:15:03
 ************************************************************************/
#include<iostream>
#include <stdexcept>

int main(int argc,char *argv[])
{
	int num1, num2;
	std::cin >> num1 >> num2;
	try{
		if(num2 == 0)
			throw std::runtime_error("divisor is 0");
		std::cout << num1 / num2 << std::endl;
	}catch(std::runtime_error error){
		std::cout << error.what() << std::endl;
	}
     
    return 0;
}

