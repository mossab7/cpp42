#include "easyfind.hpp"
#include <vector>
#include <iostream>
int main(void)
{
	std::vector <int>vec = {1,4,2,5,7,3};
	std::vector<int>::iterator it = easyfind(vec,vec[3]);
	std::cout << *it << std::endl;
	*it = 69;
	std::cout << *it << std::endl;
	return (0);
}
