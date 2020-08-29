#include "Polygon.h"
#include "Triangle.h"
#include <iostream>
using namespace std;
 
Triangle::Triangle(int side1, int side2, int side3) : Poly(3) //constructor
{
	setSides(side1, 0);//updating the first side
	setSides(side2, 1);//updating the second side
	setSides(side3, 2);//updating the third side

}

Triangle::~Triangle()//destructor, will use the Polygon's destructor
{

}
