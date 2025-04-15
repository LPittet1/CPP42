#include "Fixed.hpp"

Fixed::Fixed():value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int value):value(value << frac)
{
	std::cout << "Integer constructor called" << std::endl;
}

Fixed::Fixed(float value):value(roundf(value * (1 << frac)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& cpy)
{
	std::cout << "Copy contructor called" << std::endl;
	this->value = cpy.getRawBits();
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

Fixed& Fixed::operator=(const Fixed& cpy)
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->value = cpy.getRawBits();
	return *this;
}

float Fixed::toFloat(void) const
{
	return (float)value / (1 << frac);
}

int Fixed::toInt(void) const
{
	return value >> frac;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
