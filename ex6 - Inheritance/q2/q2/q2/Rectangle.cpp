#include "Rectangle.h"

Rectangle::Rectangle(int side1, int side2) : Poly(4)
{
	setSides(side1, 0);//updating the first side
	setSides(side2, 1);//updating the second side
	setSides(side1, 2);//updating the first side
	setSides(side2, 3);//updating the second side

}

Rectangle::~Rectangle()//destructor, will use the Polygon's destructor
{
}
