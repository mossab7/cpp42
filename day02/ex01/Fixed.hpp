#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <sstream>


class Fixed
{
	int fixed;
	public :
		static const int fraction;
		Fixed();
		~Fixed();
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed &other);
		int getRawBits(void);
		void setRawBits(int const raw);
};

int to_int(const std::string& str)
{
	std::istringstream iss(str);
	int value;
	iss >> value;
	return value;
}

std::string to_string(float f)
{
	std::ostringstream oss;
	oss << f;
	return oss.str();
}

#endif //FIXED_HPP
