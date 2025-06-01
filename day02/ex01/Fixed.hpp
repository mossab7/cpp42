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
		Fixed(float f);
		~Fixed();
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed &other);
		friend std::ostream& operator<<(std::ostream& os, const Fixed& ref);
		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits(void);
		void setRawBits(int const raw);
};


#endif //FIXED_HPP
