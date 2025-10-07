#include "BitcoinExchange.hpp"

std::string BitcoinExchange::trim(const std::string &str) {
	size_t start = str.find_first_not_of(" \t\r\n");
	if (start == std::string::npos)
		return "";
	size_t end = str.find_last_not_of(" \t\r\n");
	return str.substr(start, end - start + 1);
}

bool BitcoinExchange::isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDate(const std::string &date) {
	if (date.length() != 10)
		return false;
	
	if (date[4] != '-' || date[7] != '-')
		return false;
	
	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);
	
	for (size_t i = 0; i < yearStr.length(); ++i) {
		if (!std::isdigit(yearStr[i]))
			return false;
	}
	for (size_t i = 0; i < monthStr.length(); ++i) {
		if (!std::isdigit(monthStr[i]))
			return false;
	}
	for (size_t i = 0; i < dayStr.length(); ++i) {
		if (!std::isdigit(dayStr[i]))
			return false;
	}
	
	int year = atoi(yearStr.c_str());
	int month = atoi(monthStr.c_str());
	int day = atoi(dayStr.c_str());
	
	if (year < 1900 || year > 2030)
		return false;
	
	if (month < 1 || month > 12)
		return false;
	
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (month == 2 && isLeapYear(year))
		daysInMonth[1] = 29;
	
	if (day < 1 || day > daysInMonth[month - 1])
		return false;
	
	return true;
}

bool BitcoinExchange::isValidValue(float value) {
	return value >= 0 && value <= 1000;
}

std::map<std::string, float> BitcoinExchange::readToMap(std::string &file, char sep)
{
	std::map<std::string, float> input;
	std::ifstream iFile(file.c_str());
	std::string line;

	if (!iFile.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return input;
	}

	// Skip header line
	getline(iFile, line);
	
	while (getline(iFile, line)) {
		size_t pos = line.find(sep);
		if (pos == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string key = trim(line.substr(0, pos));
		std::string val = trim(line.substr(pos + 1));

		if (key.empty()) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		if (val.empty()) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (sep == ',') {
			input[key] = atof(val.c_str());
			continue;
		}

		if (!isValidDate(key)) {
			std::cerr << "Error: bad input => " << key << std::endl;
			continue;
		}

		char* endptr;
		float value = strtof(val.c_str(), &endptr);
		
		if (*endptr != '\0') {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		if (value < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (!isValidValue(value)) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		input[key] = value;
	}
	iFile.close();
	return input;
}

BitcoinExchange::BitcoinExchange()
{
	std::string path = "data.csv";
	data = readToMap(path, ',');
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::evaluate(std::string &inputFile) {
	std::ifstream iFile(inputFile.c_str());
	std::string line;

	if (!iFile.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	if (data.empty()) {
		std::cerr << "Error: no exchange rate data available." << std::endl;
		return;
	}

	getline(iFile, line);
	
	while (getline(iFile, line)) {
		size_t pos = line.find('|');
		if (pos == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string key = trim(line.substr(0, pos));
		std::string val = trim(line.substr(pos + 1));

		if (key.empty()) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		if (val.empty()) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (!isValidDate(key)) {
			std::cerr << "Error: bad input => " << key << std::endl;
			continue;
		}

		char* endptr;
		float value = strtof(val.c_str(), &endptr);
		
		if (*endptr != '\0') {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		if (value < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (!isValidValue(value)) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		std::map<std::string, float>::iterator curr = data.find(key);
		
		if (curr == data.end()) {
			curr = data.upper_bound(key);
			if (curr != data.begin()) {
				--curr;
			} else {
				std::cerr << "Error: no exchange rate data available for date: " << key << std::endl;
				continue;
			}
		}
		
		if (curr != data.end()) {
			float result = value * curr->second;
			std::cout << key << " => " << value << " = " << result << std::endl;
		}
	}
	
	iFile.close();
}

