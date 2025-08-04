#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>

class ScalarConverter
{
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &other);

	static void convert(const std::string &literal);
};

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

bool isDigit(const std::string &literal, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		if (!isdigit(literal[i]) && literal[i] != '.' && literal[i] != '-' && literal[i] != '+')
		{
			return false;
		}
	}
	return true;
}

void print_char(const std::string &literal)
{
	if (literal.length() == 1 && isprint(literal[0]))
	{
		std::cout << "char: '" << literal[0] << "'" << std::endl;
	}
	else
	{
		std::cout << "char: Non displayable" << std::endl;
	}
}

void print_int(const std::string &literal)
{
	try
	{
		int value = std::stoi(literal);
		std::cout << "int: " << value << std::endl;
	}
	catch (const std::out_of_range &)
	{
		std::cout << "int: Overflow" << std::endl;
	}
	catch (const std::invalid_argument &)
	{
		std::cout << "int: Invalid input" << std::endl;
	}
}

void print_float(const std::string &literal)
{
	try
	{
		float value = std::stof(literal);
		std::cout << "float: " << value << "f" << std::endl;
	}
	catch (const std::out_of_range &)
	{
		std::cout << "float: Overflow" << std::endl;
	}
	catch (const std::invalid_argument &)
	{
		std::cout << "float: Invalid input" << std::endl;
	}
}

void print_double(const std::string &literal)
{
	try
	{
		double value = std::stod(literal);
		std::cout << "double: " << value << std::endl;
	}
	catch (const std::out_of_range &)
	{
		std::cout << "double: Overflow" << std::endl;
	}
	catch (const std::invalid_argument &)
	{
		std::cout << "double: Invalid input" << std::endl;
	}
}

void ScalarConverter::convert(const std::string &literal)
{
	if (literal.empty())
	{
		std::cerr << "Error: Empty input." << std::endl;
		return;
	}
	print_char(literal);
	print_int(literal);
	print_float(literal);
	print_double(literal);
}

#endif
