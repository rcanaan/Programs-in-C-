#pragma once
#include <iostream>
#include "Point.h"
class Poli
{
private:
	Point*_poli;
	int numOfP;
public:

	// constructors
	Poli(int);    // initializing the size of the array and adding the number of points
	Poli();       // defult constructor
	Poli(const Poli &);  // copy constructor

	// set functions
	void setPoli(Point);
	void setPoint(int);

	// get functions
	int get_numOfP();
	Point get_Poli(int);

	//destructor
	~Poli();

	float hekef(Poli &);
};
#pragma once
