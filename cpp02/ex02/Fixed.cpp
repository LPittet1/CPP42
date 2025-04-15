#include "Fixed.hpp"

Fixed::Fixed():value(0)
{

}

Fixed::Fixed(int value):value(value << frac)
{

}

Fixed::Fixed(float value):value(roundf(value * (1 << frac)))
{

}

Fixed::~Fixed()
{

}

Fixed::Fixed(const Fixed& cpy)
{
	this->value = cpy.getRawBits();
}

int Fixed::getRawBits(void) const
{
	return value;
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
}

Fixed& Fixed::operator=(const Fixed& cpy)
{
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

bool	Fixed::operator>(const Fixed& comp)const
{
	return this->getRawBits() > comp.getRawBits();
}

bool	Fixed::operator<(const Fixed& comp)const
{
	return this->getRawBits() < comp.getRawBits();
}

bool	Fixed::operator>=(const Fixed& comp)const
{
	return this->getRawBits() >= comp.getRawBits();
}

bool	Fixed::operator<=(const Fixed& comp)const
{
	return this->getRawBits() <= comp.getRawBits();
}

bool	Fixed::operator==(const Fixed& comp)const
{
	return this->getRawBits() == comp.getRawBits();
}

bool	Fixed::operator!=(const Fixed& comp)const
{
	return this->getRawBits() != comp.getRawBits();
}

Fixed	Fixed::operator+(const Fixed& rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(const Fixed& rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed& rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed& rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}
Fixed&	Fixed::operator++() //pre-increment
{
	this->value++;
	return *this;
}
Fixed&	Fixed::operator--() //pre-decrement
{
	this->value--;
	return *this;
}
Fixed	Fixed::operator++(int) //post-increment
{
	Fixed tmp = *this;
	this->value++;
	return tmp;
}
Fixed	Fixed::operator--(int) //post-decrement
{
	Fixed tmp = *this;
	this->value--;
	return tmp;
}
Fixed&	Fixed::min(Fixed& fix1, Fixed& fix2)
{
	return fix1 < fix2 ? fix1 : fix2;
}
const Fixed&	Fixed::min(const Fixed& fix1, const Fixed& fix2)
{
	return fix1 < fix2 ? fix1 : fix2;
}

Fixed&	Fixed::max(Fixed& fix1, Fixed& fix2)
{
	return fix1 < fix2 ? fix2 : fix1;
}
const Fixed&	Fixed::max(const Fixed& fix1, const Fixed& fix2)
{
	return fix1 < fix2 ? fix2 : fix1;
}
