#pragma once
#include "Polygon.h"

class Triangle : public Poly//inherited class from Polygon
{
public:
	Triangle(int side1, int side2, int side3);//constructor
	~Triangle();//destructor
};