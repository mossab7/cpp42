#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>


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

#endif //FIXED_HPP
