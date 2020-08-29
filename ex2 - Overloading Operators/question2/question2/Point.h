#pragma once

class Point
{
private:
	int x;
	int y;

public:
	//constructor
	Point(int, int);
	Point();    //defult constructor

	// set functions
	void setX(int);
	void setY(int);

	// get functions
	int getX();
	int getY();

	double D(Point); // distance
};