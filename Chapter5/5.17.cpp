/*************************************************************************
    > File Name       : 5.17.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2020/05/27 18:39:51
 ************************************************************************/
#include<iostream>
#include <vector>

bool is_prefix(const std::vector<int>& lhs, const std::vector<int>& rhs)
{
	if(lhs.size() > rhs.size())
		return is_prefix(rhs, lhs);
	for (unsigned i = 0; i != lhs.size(); ++i)
	{
		if(lhs[i] != rhs[i])
			return false;
	}
	return true;
}

int main(int argc,char *argv[])
{
	std::vector<int> vec1{0, 1, 1, 2};
	std::vector<int> vec2{0, 1, 1, 2, 3, 5, 8};

	std::cout << (is_prefix(vec1, vec2) ? "yes\n" : "no\n");
     
    return 0;
}

