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
	if (literal.size() == 1 && isalpha(literal[0]))
	{
		std::cout << "char: '" << literal[0] << "'" << std::endl;
		return;
	}
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

void print_int(const std::string &temp)
{
	std::string literal = temp;
	int value;
	if (literal.size() == 1 && isalpha(literal[0]))
	{
		value = static_cast<int>(literal[0]);
		std::cout << "int: " << value << std::endl;
		return;
	}
	if (literal[literal.size() - 1] == 'f')
		literal.erase(literal.size() - 1);
	std::istringstream iss(literal);

	iss >> value;
	if (iss.eof() && !iss.fail())
	{
		std::cout << "int: " << value << std::endl;
	}
	else
	{
		std::cout << "int: impossible" << std::endl;
	}
}

void print_float(const std::string &temp)
{
	std::string literal = temp;
	float value;
	if (literal.size() == 1 && isalpha(literal[0]))
	{
		value = static_cast<float>(literal[0]);
		std::cout << "float: " << value << ".0f" << std::endl;
		return;
	}
	if (temp == "+inf" || temp == "-inf" || temp == "inf")
	{
		std::cout << "float : " << temp << "f" << std::endl;
		return;
	}
	if (literal[literal.size() - 1] == 'f')
		literal.erase(literal.size() - 1);
	std::istringstream iss(literal);

	iss >> value;
	if (iss.eof() && !iss.fail())
	{
		std::cout << "float: " << value << ((literal.find('.') == std::string::npos)? ".0f" : "f") << std::endl;
	}
	else
	{
		std::cout << "float: nanf" << std::endl;
	}
}

void print_double(const std::string &temp)
{
	std::string literal = temp;
	double value;
	if (literal.size() == 1 && isalpha(literal[0]))
	{
		value = static_cast<double>(literal[0]);
		std::cout << "double: " << value << ".0" << std::endl;
		return;
	}
	if (temp == "+inf" || temp == "-inf" || temp == "inf")
	{
		std::cout << "double : " << temp << std::endl;
		return;
	}
	if (literal[literal.size() - 1] == 'f')
		literal.erase(literal.size() - 1);
	std::istringstream iss(literal);

	iss >> value;
	if (iss.eof() && !iss.fail())
	{
		std::cout << "double: " << value << ((literal.find('.') == std::string::npos)? ".0" : "") << std::endl;
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
