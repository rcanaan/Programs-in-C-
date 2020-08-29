#pragma once
#include <iostream>
using namespace std;
//setting class "Rational"- for rational numbers
class Rational
{
private:
	int n;//numerator
	int d;//denumerator
	void reducing();//minimize the fraction

public:
	Rational();//default constructor
	Rational(int a = 1, int b = 1);//copy constructor

	void setNumer(int myNumer);//setting value into the mone 
	int getNumer();
	void setDenom(int myDenom);//setting value into the mechane
	int getDenom();

	void print();//printing
	void equal();//this function checks if the two numbers are equale or not

	bool operator >= (Rational & rhs);//if a > or = b
	bool operator > (Rational & rhs);//if a > b
	bool operator < (Rational & rhs);//if a < b
	bool operator != (Rational & rhs);//checking for difference

	Rational operator ++ (int);//a++
	Rational operator -- (int);//a--
	Rational operator -- ();//--a

	Rational operator +(Rational & rhs);//definding the + operator
	Rational operator - (Rational & rhs);//definding the - operator
	Rational operator / (Rational & rhs);//definding the / operator



	~Rational();//destructor
};
