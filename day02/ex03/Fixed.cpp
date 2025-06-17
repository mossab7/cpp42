#include "Fixed.hpp"

const int Fixed::fraction = 8;

float Fixed::toFloat(void) const
{
	return (fixed / static_cast<float>(1 << fraction));
}

int Fixed::toInt(void) const
{
	return (fixed / (1 << fraction));
}

Fixed::Fixed(float f)
{
	fixed = static_cast<int>(roundf(f * (1 << fraction)));
}

std::ostream& operator<<(std::ostream& os, const Fixed& ref)
{
	os << ref.toFloat();
	return os;
}
Fixed::Fixed() : fixed(0)
{
}
Fixed::~Fixed()
{
}
Fixed::Fixed(const Fixed &other)
{
	fixed = other.fixed;
}
Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		fixed = other.fixed;
	}
	return (*this);
}
int Fixed::getRawBits(void)
{
	return (fixed);
}
void Fixed::setRawBits(int const raw)
{
	fixed = raw;
}
bool Fixed::operator>(const Fixed &other) const
{
	return (fixed > other.fixed);
}
bool Fixed::operator<(const Fixed &other) const
{
	return (fixed < other.fixed);
}
bool Fixed::operator>=(const Fixed &other) const
{
	return (fixed >= other.fixed);
}
bool Fixed::operator<=(const Fixed &other) const
{
	return (fixed <= other.fixed);
}
bool Fixed::operator==(const Fixed &other) const
{
	return (fixed == other.fixed);
}
bool Fixed::operator!=(const Fixed &other) const
{
	return (fixed != other.fixed);
}
Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.fixed = fixed + other.fixed;
	return result;
}
Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.fixed = fixed - other.fixed;
	return result;
}
Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result.fixed = (fixed * other.fixed) / (1 << fraction);
	return result;
}
Fixed Fixed::operator/(const Fixed &other) const
{
	if (other.fixed == 0)
	{
		std::cerr << "Error: Division by zero" << std::endl;
		return Fixed(0);
	}
	Fixed result;
	result.fixed = (fixed * (1 << fraction)) / other.fixed;
	return result;
}
Fixed &Fixed::operator++(void)
{
	fixed += 1; 
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	fixed += 1;
	return temp;
}

Fixed &Fixed::operator--(void)
{
	fixed -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	fixed -= 1;
	return temp;
}
Fixed &Fixed::operator+=(const Fixed &other)
{
	fixed += other.fixed;
	return *this;
}
Fixed &Fixed::operator-=(const Fixed &other)
{
	fixed -= other.fixed;
	return *this;
}
Fixed &Fixed::operator*=(const Fixed &other)
{
	fixed = (fixed * other.fixed) / (1 << fraction);
	return *this;
}
Fixed &Fixed::operator/=(const Fixed &other)
{
	if (other.fixed == 0)
	{
		std::cerr << "Error: Division by zero" << std::endl;
		return *this;
	}
	fixed = (fixed * (1 << fraction)) / other.fixed;
	return *this;
}
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}
Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? const_cast<Fixed&>(a) : const_cast<Fixed&>(b);
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}
Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? const_cast<Fixed&>(a) : const_cast<Fixed&>(b);
}