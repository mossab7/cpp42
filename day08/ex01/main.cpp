#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	std::vector<int> vec;
	vec.push_back(4);
	vec.push_back(44);
	vec.push_back(42);
	vec.push_back(46);
	vec.push_back(49);
	vec.push_back(35);
	try {
		sp.addNumber(vec.begin(),vec.end());
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
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return (0);
}
