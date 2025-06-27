#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>

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
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);
		Fixed &operator+=(const Fixed &other);
		Fixed &operator-=(const Fixed &other);
		Fixed &operator*=(const Fixed &other);
		Fixed &operator/=(const Fixed &other);
		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits(void);
		void setRawBits(int const raw);
		static Fixed& min(Fixed &a, Fixed &b);
		static Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& ref);

#endif //FIXED_HPP
