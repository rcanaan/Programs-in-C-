#include "Polygon.h"
#include "Point.h"

Polygon::Polygon()//default constructor
{

}

Polygon::Polygon(int n)//constructor
{
	numVertex = 0;//defining the num of vertexes
	poly = new Point[n];//allocating the array size
}

Polygon::Polygon(const Polygon & vec)//copy constructor
{
	numVertex = vec.numVertex;
	poly = new Point[numVertex];
	for (int i = 0; i < numVertex; i++)
		poly[i] = vec.poly[i];//copying all the numbers from vec to data
}

Polygon::~Polygon()//destructor
{
	if (poly)
		delete[] poly;
	poly =nullptr;//NULL
}

float Polygon::circu(/*const Polygon & P*/)//circumference ("hekef") 
{
	float sum = 0;
	for (int i = 0; i < (numVertex - 1); i++)
		sum = sum + poly[i].distance(poly[i + 1]);
	sum = sum + poly[numVertex - 1].distance(poly[0]);
	return sum;
}
Point Polygon::get_Poli(int i)
{
	return poly[i];  // returning the value of the array at a specific index
}

void Polygon::setPoli(Point & a) // entering a point to the points array
{
	poly[numVertex] = a;
	numVertex++;  // updating the num of points
}

void Polygon::setPoint(int n)
{
	this->numVertex = n;
}

int Polygon::get_numVertex()
{
	return numVertex;
}
