#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <sstream>

class ScalarConverter
{
	private :
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
	public:
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &other);

		static void convert(const std::string &literal);
};


#endif
