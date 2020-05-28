/*************************************************************************
    > File Name       : 5.3.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 20/5/25 12:01:54
 ************************************************************************/
#include<iostream>

int main(int argc,char *argv[])
{
	int sum = 0, val = 1;
	while (val <= 10) 
		sum += val, ++val;
	std::cout << "sum of 1 to 10 inclusive is " << sum << std::endl;
     
    return 0;
}

