#pragma once
#include "Point.h"
class Polygon
{
	Point * poly;//pointer to an array of vertexes
	int numVertex;//the num of vertexes in polygon

public:
	Polygon();//default constructor
	Polygon(int n);//constructor
	Polygon(const Polygon &);//copy constructor
	~Polygon();//destructor

	float circu(/*const Polygon & P*/);//circumference ("hekef") 

	Point get_Poli(int);
	void setPoli(Point &);
	void setPoint(int);
	int get_numVertex();




};