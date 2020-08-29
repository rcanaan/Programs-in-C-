#include "Poli.h"
#include "Point.h"

Poli::Poli(int num)   //constructor
{
	numOfP = 0;
	this->_poli = new Point[num];
}

Poli::Poli()  // defult constructor
{
	//_poli = new Point;
	//numOfP = 0; //1
}

Poli::Poli(const Poli & a)   // copy constructor- not a shallo copy
{
	this->numOfP = a.numOfP;
	for (int i = 0; i < numOfP/*-1*/; i++)
	{
		_poli[i] = a._poli[i]; //a.get_Poli(i);
	}
}

void Poli::setPoli(Point a) // entering a point to the points array
{
	_poli[numOfP] = a;
	numOfP++;  // updating the num of points
}

void Poli::setPoint(int n)
{
	this->numOfP = n;
}

int Poli::get_numOfP()
{
	return numOfP;   // returning number of points
}

Point Poli::get_Poli(int i)
{
	return _poli[i];  // returning the value of the array at a specific index
}

Poli::~Poli()
{
	if (_poli)
		delete[]_poli; // deleting the array we made in the end of the program
}

float Poli::hekef(Poli & R)
{
	int sum = 0;
	for (int i = 0; i < R.get_numOfP(); i++)
	{
		if (i == R.get_numOfP() - 1) // wich means that we've reached the last point 
		{
			sum += R.get_Poli(0).D(R.get_Poli(i));
		}
		else
		{
			sum += R.get_Poli(i + 1).D(R.get_Poli(i)); // as long as we did'nt reach the last point
		}
	}
	return sum;
}
