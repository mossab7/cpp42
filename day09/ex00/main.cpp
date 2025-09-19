#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
	if (ac != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	
	try {
		BitcoinExchange bitc;
		std::string path = av[1];
		bitc.evaluate(path);
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}
