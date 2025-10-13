#include "Span.hpp"
#include "../ex02/MutantStack.hpp"
int main()
{
	Span sp = Span(10);
	std::vector<int> vec;
	vec.push_back(4);
	vec.push_back(44);
	vec.push_back(42);
	vec.push_back(46);
	vec.push_back(49);
	vec.push_back(35);
	MutantStack<int> stack;
	stack.push(9);
	stack.push(94);
	stack.push(92);
	stack.push(96);
	stack.push(99);
	stack.push(95);

	{
		Span temp = sp;
		Span copy(sp);
		try
		{
			copy.shortestSpan();
			temp.shortestSpan();
			copy.longestSpan();
			temp.longestSpan();
		}
		catch(std::exception &err){
			std::cerr << err.what() << std::endl;
		}
	}

	try {
		sp.addNumbers(vec.begin(),vec.end());
		sp.addNumbers(stack.begin(), stack.end());
	}
	catch(std::exception &err){
		std::cerr << err.what() << std::endl;
	}
	try{
		sp.addNumber(16);
	}
	catch(std::exception &err){
		std::cout << err.what() << std::endl;
	}
	try {
		sp.addRange(16);
	}
	catch(std::exception &err){
		std::cout << err.what() << std::endl;
	}

	{
		Span temp = sp;
		Span copy(sp);
		try
		{
			std::cout << "From copy " << copy.shortestSpan() << std::endl;
			std::cout << "From temp " << temp.shortestSpan() << std::endl;
			std::cout << "From copy " << copy.longestSpan() << std::endl;
			std::cout << "From temp " << temp.longestSpan() << std::endl;
		}
		catch(std::exception &err){
			std::cerr << err.what() << std::endl;
		}
	}

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return (0);
}
