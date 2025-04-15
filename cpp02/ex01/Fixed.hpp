#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int value;
	static const int frac = 8;
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& cpy);
	~Fixed();
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	Fixed&	operator=(const Fixed& cpy);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);