#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	std::vector<int> vec = {5,3,1,6,8};
	sp.addNumber(vec.begin(),vec.end());
	// try {
	// 	sp.addNumber(16);
	// }
	// catch(std::exception &err)
	// {
	// 	std::cout << err.what() << std::endl;
	// }
	// try {
	// 	sp.addRange(16);
	// }
	// catch(std::exception &err)
	// {
	// 	std::cout << err.what() << std::endl;
	// }
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return (0);
}
