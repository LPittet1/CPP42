#pragma once

#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;
public:
	Point();
	Point(const float x, const float y);
	Point(const Point& cpy);
	Point& operator=(Point& cpy);
	~Point();
	const Fixed getX() const;
	const Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
