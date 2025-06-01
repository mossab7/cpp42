#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <sstream>


class Fixed
{
	int fixed;
	public :
		static const int fraction;
		static int toInt(const std::string &str);
		static std::string toString(float f);
		Fixed();
		Fixed(float f);
		~Fixed();
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed &other);
		void operator>>();
		int getRawBits(void);
		void setRawBits(int const raw);
};

float ft_roundf(float value)
{
	return (value >= 0.0f) ? (int)(value + 0.5f) : (int)(value - 0.5f);
}

Fixed::Fixed(float f)
{
	fixed = static_cast<int>(ft_roundf(f * (1 << fraction)));
}

#endif //FIXED_HPP
