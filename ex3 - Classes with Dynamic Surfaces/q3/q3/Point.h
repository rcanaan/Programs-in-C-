#pragma once
class Point
{
private:
	int x;
	int y;

public:

	Point();//default constructor
	Point(int, int);//constructor
	
	void setX(int myX);//setting value
	int getX();
	void setY(int myY);//setting value
	int getY();

	float distance(Point & p); //calculating the distance between 2 points
	

};
