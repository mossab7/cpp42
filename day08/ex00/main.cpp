#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main(void)
{
	std::vector <int>vec;
	vec.push_back(4);
	vec.push_back(34);
	vec.push_back(45);
	vec.push_back(23);
	vec.push_back(54);
	std::vector<int>::iterator it = easyfind(vec,vec[3]);
	std::cout << *it << std::endl;
	*it = 69;
	std::cout << *it << std::endl;
	return (0);
}
