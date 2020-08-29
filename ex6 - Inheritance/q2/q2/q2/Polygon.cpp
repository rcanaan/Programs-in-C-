#include "Polygon.h"
#include <iostream>
using namespace std;

Poly::Poly()//default constructor
{
	numSides = 0;
	sides = new int[0];
}

Poly::Poly(int n)//constructor, bulid the array "sides"
{
	int val;
	numSides = n;
	sides = new int[numSides];

	if ((numSides > 4))//in case the sides is not triangle or rectangle
	{
		cout << "enter sides for polygon:" << endl;
		for (int i = 0; i < numSides; i++)
		{
			cin >> val;
			sides[i] = val;//putting the length inside the vector
		}
	}
}

Poly::Poly(const Poly & p)//copy constructor
{
	numSides = p.numSides;
	for (int i = 0; i < numSides; i++)
		sides[i] = p.sides[i];
}

Poly::~Poly()//destructor
{
	if (sides)//if there are data inside "sides"
	delete[] sides;
}

int Poly::getNumSides()//getter function (no need for setter)
{
	return numSides;
}

void Poly::setNumSides(int n)//setter function
{
	numSides = n;
}

void Poly::setSides(int value, int index)//setter function
{
	sides[index] = value;
}

int Poly::perimeter()//"hekef" of the Polygon
{
	int perimeter = 0;//will be using as "sum"
	for (int i = 0; i < numSides; i++)
		perimeter = perimeter+ sides[i];//summing all the length
	
	return perimeter;
}

bool Poly::operator==(Poly & p)//checks for equality between two polygons
{
	bool sumSides = false;
	bool num = false;

	if (numSides == p.numSides)//in case the num of sides equale
		num = true;
	if (this->perimeter() == p.perimeter())
		sumSides = true;
	if (sumSides && num)//if both of them are true
		return true;
	return false;
}

void Poly::printSides()//printing
{
	cout << "the side is:" << endl;
	for (int i = 0; i < numSides; i++)
		cout << sides[i] << " ";
	cout << endl;
}
