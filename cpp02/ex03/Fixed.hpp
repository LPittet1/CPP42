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
	bool	operator>(const Fixed& comp)const;
	bool	operator<(const Fixed& comp)const;
	bool	operator>=(const Fixed& comp)const;
	bool	operator<=(const Fixed& comp)const;
	bool	operator==(const Fixed& comp)const;
	bool	operator!=(const Fixed& comp)const;
	Fixed	operator+(const Fixed& cpy)const;
	Fixed	operator-(const Fixed& cpy)const;
	Fixed	operator*(const Fixed& cpy)const;
	Fixed	operator/(const Fixed& cpy)const;
	Fixed&	operator++(); //pre-increment
	Fixed&	operator--(); //pre-decrement
	Fixed	operator++(int); //post-increment
	Fixed	operator--(int); //post-decrement
	static Fixed&	min(Fixed& fix1, Fixed& fix2);
	static const Fixed&	min(const Fixed& fix1, const Fixed& fix2);
	static Fixed&	max(Fixed& fix1, Fixed& fix2);
	static const Fixed&	max(const Fixed& fix1, const Fixed& fix2);

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);