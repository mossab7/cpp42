#include "RPN.HPP"

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		std::cerr << "ivalid arguments" << std::endl;
		return (0);
	}
	std::string exp = argv[1];
	Rpn rpn;
	try {
		std::cout << rpn.evaluate(exp) << std::endl;
	}
	catch(std::exception &err)
	{
		std::cerr << err.what() << std::endl;
	}
}
