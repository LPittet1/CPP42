#include "Point.hpp"

Fixed	get_area(Point a, Point b, Point c)
{
	Fixed area = ((a.getX() - c.getX()) * (b.getY() - a.getY())
				- (a.getX() - b.getX()) * (c.getY() - a.getY())) / 2;
	return area > 0 ? area : area * -1;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed wholeArea = get_area(a, b, c);
	Fixed areaABP	= get_area(a, b, point);
	Fixed areaACP	= get_area(a, point, c);
	Fixed areaBCP	= get_area(point, b, c);
	if (areaABP == 0 || areaACP == 0 || areaBCP == 0)
		return false;
	Fixed totalArea = areaABP + areaACP + areaBCP;
	if (totalArea != wholeArea)
		return false;
	return true;
}