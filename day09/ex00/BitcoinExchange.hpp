#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <sstream>

class BitcoinExchange {
private:
	std::map<std::string, float> data;

	std::map<std::string, float> readToMap(std::string &file, char sep);
	bool isValidDate(const std::string &date);
	bool isLeapYear(int year);
	bool isValidValue(float value);
	std::string trim(const std::string &str);

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void evaluate(std::string &inputFile);
};
#endif //BITCOINEXCHANGE
