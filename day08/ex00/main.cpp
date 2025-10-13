#include "easyfind.hpp"
#include <vector>
#include <iostream>
#include "../ex02/MutantStack.hpp"

int main(void)
{
	std::vector <int>vec;
	vec.push_back(4);
	vec.push_back(34);
	vec.push_back(45);
	vec.push_back(23);
	vec.push_back(54);
	std::vector<int>::iterator v_it = easyfind(vec,vec[3]);
	std::cout << *v_it << std::endl;
	*v_it = 69;
	std::cout << *v_it << std::endl;

	MutantStack <int>stack;
	stack.push(4);
	stack.push(34);
	stack.push(45);
	stack.push(23);
	stack.push(54);
	MutantStack<int>::iterator s_it = easyfind(stack,*(stack.begin() + 3));
	std::cout << *s_it << std::endl;
	*s_it = 69;
	std::cout << *s_it << std::endl;

	return (0);
}
