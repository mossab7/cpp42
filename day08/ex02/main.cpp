#include "MutantStack.hpp"
#include <iostream>
#include <stack>
int main(void)
{
	MutantStack <int>mstack;
	mstack.push_back(10);
	mstack.push_back(20);
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::stack<int> s(mstack);
	while (!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}
	return (0);
}
