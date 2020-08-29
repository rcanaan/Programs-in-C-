#pragma once
//definding class
#include <iostream>
using namespace std;
class Rational
{
private:
	int numerator;//mone
	int denominator;//mechane
	void decrease();//reducing
	
public:
	void setNumer(int myNumer);//setting value into the mone 
	int getNumer();
	void setDenom(int myDenom);//setting value into the mechane
	int getDenom();
	void print();//printing
	bool equal(Rational r);//this function checks if the two numbers are equale or not

};