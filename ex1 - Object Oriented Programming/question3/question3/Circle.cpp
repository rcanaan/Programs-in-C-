#include "Circle.h"
#include <cmath>
void Circle::setRad(int r)
{
	rad = r;
}
int Circle::getRad()
{
	return rad;
}
void Circle::setCtr(Point my_center)
{
	center = my_center;
}
Point Circle::getCtr()
{
	return center;
}
float Circle::circleS()//surface
{
	float pi = 3.14;
	float surface;
	surface = (pi * pow(rad, 2));
	return surface;
}
float Circle::circleP()//extent
{
	float const pi = 3.14;
	float circu;//the short word for circumference
	circu = 2 * pi*rad;
	return circu;
}
int Circle::inOnOut(Point p)
{
	float d;//distance
	d = sqrt(pow((center.getX() - p.getX()), 2) + pow((center.getY() - p.getY()), 2));//distance equation
	if (d == rad)//if the point on the circle
		return 0;
	else if (d < rad)//if the point in the circle
		return -1;
	else             //if the point out of the circle
		return 1;
}










