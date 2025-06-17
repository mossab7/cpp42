#include "Point.hpp"

Fixed area(Fixed x1, Fixed y1, Fixed x2, Fixed y2, Fixed x3, Fixed y3)
{
   return std::abs(((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0).toFloat());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed A = area(a.getX(), a.getY(), b.getX(), b.getY(), c.getX(), c.getY());
	Fixed A1 = area(point.getX(), point.getY(), b.getX(), b.getY(), c.getX(), c.getY());
	Fixed A2 = area(a.getX(), a.getY(), point.getX(), point.getY(), c.getX(), c.getY());
	Fixed A3 = area(a.getX(), a.getY(), b.getX(), b.getY(), point.getX(), point.getY());
	return (A == (A1 + A2 + A3));
}


int main( void ) 
{
	Point a(Fixed(0), Fixed(0));
	Point b(Fixed(5), Fixed(0));
	Point c(Fixed(2.5), Fixed(5));
	Point point(Fixed(2.5), Fixed(2));

	if (bsp(a, b, c, point))
		std::cout << "Point is inside the triangle." << std::endl;
	else
		std::cout << "Point is outside the triangle." << std::endl;

	return 0;
}
