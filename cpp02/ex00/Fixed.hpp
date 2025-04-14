#pragma once

#include <iostream>

class Fixed
{
private:
	int value;
	static const int frac = 8;
public:
	Fixed();
	Fixed(const Fixed& cpy);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	Fixed &operator=(const Fixed& cpy);
};

