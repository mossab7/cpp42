#include "BitcoinExchange.hpp"

int main(int ac,char *av[])
{
	BitcoinExchange bitc;
	std::string path = av[1];
	bitc.evaluate(path);
	return (0);
}
