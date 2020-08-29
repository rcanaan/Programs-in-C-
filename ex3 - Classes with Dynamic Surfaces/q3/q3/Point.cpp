#include <iostream>
#include "Point.h"
using namespace std;
Point::Point()//default constructor
{
	x = 0;
	y = 0;
}
Point::Point(int myX, int myY)//constructor
{
	x = myX;
	y = myY;
}
void Point::setX(int myX)
{
	x = myX;
}
int Point::getX()
{
	return x;
}
void Point::setY(int myY)
{
	y = myY;
}
int Point::getY()
{
	return y;
}

float Point::distance(Point & p)//calculating the distance between 2 points
{
	float d = sqrt(pow((x - p.x), 2.0) + pow((y - p.y), 2.0));//distance equation
	return d;

}
