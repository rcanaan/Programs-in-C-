#pragma once
#include <iostream>
using namespace std;
class Poly	//father class
{
protected:
	int numSides;	// the number of edges at the Polygon
	int * sides;	//contains the length of each side, and the array's size is like the numSides

public:
	Poly();//default constructor
	Poly(int n);//constructor, bulid the array "sides"
	Poly(const Poly & p);//copy constructor
	~Poly();//destructor

	int getNumSides();//getter function 
	void setNumSides(int n);//setter function
	void setSides(int value, int index);//setter function
	int perimeter();//"hekef" of the Polygon
	bool operator == (Poly & p);//checks for equality between two polygons
	void printSides();//printing

};
