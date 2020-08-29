//this file includes all the functions 
#include <iostream>
using namespace std;
#include "Rational.h"

void Rational::setNumer(int myNumer)//setting value into the mone
{
	numerator = myNumer;
}
int Rational::getNumer()
{
	return numerator;
}
void Rational::setDenom(int myDenom)//setting value into the mechane
{
	if (myDenom == 0)//it is forbidden to put 0 at the mechane (if this is "infi" this is another case ;-) )
		denominator = 1;
	else
		denominator = myDenom;
}
int Rational::getDenom()
{
	return denominator;
}
void Rational::print()
{
	cout << numerator << "/" << denominator;
}
void Rational::decrease()//this function reducing the fraction
{
	if (numerator > denominator)//if the mechane is smaller than the mone
	{
		for (int i = denominator; i >= 2; i--)
		{
			if ((denominator % i == 0) && (numerator % i == 0))
			{
				numerator = numerator / i;
				denominator = denominator / i;
				return;
			}
		}
	}
	else if (numerator < denominator)//if the mone is smaller than the mechane
		for (int i = numerator; i >= 2; i--)
		{
			if ((numerator % i == 0) && (denominator% i == 0))
			{
				numerator = numerator / i;
				denominator = denominator / i;
				return;
			}
		}
	else//in case there is no option for reducing
		return;
		
}
bool Rational::equal(Rational r)//this function checks if the two numbers are equale or not
                                 //i didn't know if the values would set "by value" or "by reference"' therefor i created copies in case it will set by reference
{
	Rational temp_r1, temp_r2;//creating local r1 and r2 
	temp_r1.numerator = numerator;
	temp_r1.denominator = denominator;
	temp_r2.numerator = r.numerator;
	temp_r2.denominator = r.denominator;
	if ((temp_r1.numerator == temp_r1.denominator) && (temp_r2.numerator == temp_r2.denominator))//in case the numbers are whole
		return true;
	temp_r1.decrease();//reducing the valuse of temp_r1
	temp_r2.decrease(); //reducing the valuse of temp_r2
	if ((temp_r1.numerator == temp_r2.numerator) && (temp_r1.denominator == temp_r2.denominator))
		return true;
	else
		return false;


}
