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
float ft_roundf(float value)
{
	return (value >= 0.0f) ? (int)(value + 0.5f) : (int)(value - 0.5f);
}

Fixed::Fixed(float f)
{
	std::cout << "Float constructor called" << std::endl;
	fixed = static_cast<int>(ft_roundf(f * (1 << fraction)));
}

std::ostream& operator<<(std::ostream& os, const Fixed& ref)
{
	os << ref.fixed / static_cast<float>(1 << Fixed::fraction);
	return os;
}
Fixed::Fixed() : fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	fixed = other.fixed;
}
Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		fixed = other.fixed;
	}
	return (*this);
}
int Fixed::getRawBits(void)
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixed);
}
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	fixed = raw;
}
