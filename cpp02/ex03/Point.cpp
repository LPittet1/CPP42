#include "Point.hpp"

Point::Point(): x(0), y(0)
{

}

Point::Point(const float x, const float y): x(x), y(y)
{

}

Point::Point(const Point& cpy): x(cpy.x), y(cpy.y)
{

}

Point& Point::operator=(Point& cpy)
{
	(void)cpy;
	return  *this;
}

Point::~Point()
{

}

const Fixed Point::getX() const
{
	return x;
}
const Fixed Point::getY() const
{
	return y;
}