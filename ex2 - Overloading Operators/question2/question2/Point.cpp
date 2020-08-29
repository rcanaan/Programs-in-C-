#include "Point.h"
#include<iostream>
#include<cmath>
using namespace std;


Point::Point(int _x, int _y)
{
	x = _x;
	y = _y;
}

Point::Point()
{
	x = 0;  // initializing the values of the point
	y = 0;
}

void Point::setX(int _x)
{
	x = _x;
}

void Point::setY(int _y)
{
	y = _y;
}

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return x;
}

double Point::D(Point a)
{
	float d = sqrt(pow(x - a.x/*getX()*/, 2.0) + pow(y - a.y/*getY()*/, 2.0));
	return d;
}
