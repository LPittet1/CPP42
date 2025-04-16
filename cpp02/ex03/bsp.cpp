#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float wholeArea = (a.getX() * (b.getY() - c.getY())).toFloat()
					+ (b.getX() * (c.getY() - a.getY())).toFloat()
					+ (c.getX() * (a.getY() - b.getY())).toFloat();
	float areaABP	= (a.getX() * (b.getY() - point.getY())).toFloat()
					+ (b.getX() * (point.getY() - a.getY())).toFloat()
					+ (point.getX() * (a.getY() - b.getY())).toFloat();
	float areaACP	= (a.getX() * (point.getY() - c.getY())).toFloat()
					+ (point.getX() * (c.getY() - a.getY())).toFloat()
					+ (c.getX() * (a.getY() - point.getY())).toFloat();
	float areaBCP	= (point.getX() * (b.getY() - c.getY())).toFloat()
					+ (b.getX() * (c.getY() - point.getY())).toFloat()
					+ (c.getX() * (point.getY() - b.getY())).toFloat();
	if (areaABP == 0 || areaACP == 0 || areaBCP == 0)
		return false;
	float totalArea = areaABP + areaACP + areaBCP;
	if (totalArea != wholeArea)
		return false;
	return true;
}