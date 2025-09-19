#include "ScalarConverter.hpp"

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

void print_char(const std::string &literal)
{
    std::istringstream iss(literal);
    int value;
    if ((iss >> value))
    {
        char c = static_cast<char>(value);
        if (isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        return;
    }
    std::cout << "char: impossible" << std::endl;
    return;
}

void print_int(const std::string &literal)
{
	std::istringstream iss(literal);
	
	int value;
	if (iss >> value)
	{
		std::cout << "int: " << value << std::endl;
	}
	else
	{
		std::cout << "int: impossible" << std::endl;
	}
}

void print_float(const std::string &literal)
{
	std::istringstream iss(literal);
	
	float value;
	if (iss >> value)
	{
		std::cout << "float: " << value << ".0f" << std::endl;
	}
	else
	{
		std::cout << "float: nanf" << std::endl;
	}
}

void print_double(const std::string &literal)
{
	std::istringstream iss(literal);
	
	double value;
	if (iss >> value)
	{
		std::cout << "double: " << value << ".0" << std::endl;
	}
	else
	{
		std::cout << "double: nan" << std::endl;
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