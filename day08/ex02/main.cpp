#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <stack>
#include <cstddef>
int main(void)
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	MutantStack<int> mstack;
	mstack.push_range(vec.begin(), vec.end());
	mstack.push(6);
	mstack.push(7);
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << "-----------------size: " << mstack.size() << std::endl;
	std::stack<int> s(mstack);
	while (!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}
	return (0);
}
