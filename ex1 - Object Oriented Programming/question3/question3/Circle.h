#pragma once
#include <iostream>
#include <cmath>
#include "Point.h"
using namespace std;

class Circle
{
private:
	Point center;//the main points of the circle
	int rad;

public:
	void setRad(int r);//setting value into radius
	int getRad();
	void setCtr(Point my_center);//setting the points value
	Point getCtr();
	float circleS();//the circle surface
	float circleP();//the curcle extent
	int inOnOut(Point p);//if the specific point is on, out or in the circle

};
