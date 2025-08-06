#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>

class BitcoinExchange {
private:
	std::map<std::string, float> data;

	std::map<std::string, float> readToMap(std::string &file, char sep);

public:
	BitcoinExchange();
	~BitcoinExchange();

	void evaluate(std::string &inputFile);
};

std::map<std::string, float> BitcoinExchange::readToMap(std::string &file, char sep)
{
	std::map<std::string, float> input;
	std::ifstream iFile(file);
	std::string line;

	if (!iFile.is_open()) {
		std::cerr << "Error: Could not open file " << file << std::endl;
		return input;
	}

	getline(iFile, line);
	while (getline(iFile, line)) {
		size_t pos = line.find(sep);
		if (pos == std::string::npos)
			continue;

		std::string key = line.substr(0, pos);
		std::string val = line.substr(pos + 1);

		if (key.empty() || val.empty())
			continue;

		input[key] = atof(val.c_str());
	}
	return input;
}

BitcoinExchange::BitcoinExchange()
{
	std::string path = "data.csv";
	data = readToMap(path, ',');
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::evaluate(std::string &inputFile) {
	std::map<std::string, float> input = readToMap(inputFile, '|');

	for (std::map<std::string, float>::iterator it = input.begin(); it != input.end(); ++it)
	{
		std::map<std::string, float>::iterator curr = data.find(it->first);
		if (curr == data.end()) {
			curr = data.upper_bound(it->first);
			if (curr != data.begin())
				--curr;
		}
		if (curr != data.end()) {
			std::cout << it->first << " => " << it->second
					  << " = " << it->second * curr->second << std::endl;
		}
		else {
			std::cout << "No exchange rate data available for: " << it->first << std::endl;
		}
	}
}

#endif //BITCOINEXCHANGE
