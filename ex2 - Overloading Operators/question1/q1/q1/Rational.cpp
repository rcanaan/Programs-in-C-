#include "Rational.h"
#include <iostream>
using namespace std;

Rational::Rational()//default constructor
{
	n = 1;
	d = 1;
}
Rational::Rational(int a, int b)//copy constructor
{
	  // while fraction is ligeal
	
		n = a;
		d = b;
	
	if (b == 0)
	{
		this->n = a;
		cout << "ERROR" << endl;  // if the fraction is iligeal replacing the iligeal denominator with 1
		this->d = 1;
	}
}

void Rational::setNumer(int myNumer)//setting value into the mone
{
	n = myNumer;
}
int Rational::getNumer()
{
	return n;
}
void Rational::setDenom(int myDenom)//setting value into the mechane
{
	d = myDenom;
}
int Rational::getDenom()
{
	return d;
}

void Rational::reducing()//this function reducing the fraction
{
	if (n > d)//if the denumerator is smaller than the numerator
	{
		for (int i = d; i >= 2; i--)
		{
			if ((d % i == 0) && (n % i == 0))
			{
				n = n / i;
				d = d / i;
				return;
			}
		}
	}
	else if (n < d)//if the numerator is smaller than the denumerator
		for (int i = n; i >= 2; i--)
		{
			if ((n % i == 0) && (d% i == 0))
			{
				n = n / i;
				d = d / i;
				return;
			}
		}
	else//in case there is no option for reducing
		return;
}

void Rational::print()//printing
{
	(*this).equal();//cheking for eauality 
	if (n == 0 || d == 1)//printing just the numerator
		cout << n;
	else//in every other case
	cout << n << "/" << d;
}
void Rational::equal()//this function checks if the two numbers are equale or not
{
	if (d < 0)
	{
		n = -n; d = -d;
	}
	if (d==0)
	{
		return;
	}
	for (int i = d; i > 1; --i) //start from denumerator that is defintly positive 
	{
		if (!(n%i) && !(d%i))//both numbers div in the same num
		{
			n = n / i;
			d = d / i;
		}
	}
}
bool Rational:: operator >= (Rational & rhs)
{
	//i will seperate to a few options:
	//1. if both of the numbers are positive, 
	//2.both of negetive
	//3. negative and positive
	//4. positive and negative
	if ((n * rhs.d) == (d * rhs.n))//in case the numbers are equales
		return true;
	if ((n * d > 0) && (rhs.n * rhs.d > 0))//both positive
	{
		if (n * rhs.d > d * rhs.n)
			return true;
		else
			return false;
	}
	if ((n * d < 0) && (rhs.n * rhs.d < 0))//both are negative
	{
		if (n * rhs.d > d * rhs.n)
			return true;
		else
			return false;
	}
	if ((n * d < 0) && (rhs.n * rhs.d > 0))//negative and positive
		return false;
	
	else //positive and negative
		return true;
}

bool Rational::operator > (Rational & rhs)
{
	
	if ((n * d > 0) && (rhs.n * rhs.d > 0))//both positive
	{
		if (n * rhs.d > d * rhs.n)
			return true;
		else
			return false;
	}
	if ((n * d < 0) && (rhs.n * rhs.d < 0))//both are negative
	{
		if (n * rhs.d > d * rhs.n)
			return true;
		else
			return false;
	}
	if ((n * d < 0) && (rhs.n * rhs.d > 0))//negative and positive
		return false;
	 //((n * d > 0) && (rhs.n * rhs.d < 0))//positive and negative
	else	
	return true;
}
bool Rational::operator < (Rational & rhs)
{
	if (*this!=rhs&&!(*this>rhs))//by using the previuos operators, in case the number different and not bigger
	{
		return true;
	}
	return false;
}
bool Rational::operator != (Rational & rhs)
{
	//reducing();//reducing the rhs number
	//reducng
	//if ((n != rhs.n) || (d != rhs.d))
	//{
	//	return false;
	//}
	//return true;
	int nN = n * rhs.d;//creating multipied numerator
	int nD = d * rhs.n;//creating multiplied denumerator
	if (nN != nD)//if they are differet
		return true;
	return false;
}
Rational Rational:: operator ++ (int)//n++
{
	Rational temp = *this;
	n += d;//numerator = numerator + denumerator
	return temp;
}

Rational Rational::operator -- (int)//n--
{
	Rational temp = *this;
	n -= d;//numerator = numerator - denumerator
	return temp;
}
Rational Rational::operator -- ()//--n
{
	n -= d;//numerator = numerator - denumerator
	return *this;
}
Rational Rational::operator +(Rational & rhs)
{
	int newN = (n * rhs.getNumer()) + (rhs.getNumer()*d);//new numerator
	int newD = d * rhs.getDenom();//new denumerator
	Rational temp(newN, newD);
	return temp;
}
Rational Rational ::operator - (Rational & rhs)//definding "-" operator
{
	int newN = (n * rhs.d) - (d * rhs.n);
	int newD = d * rhs.d;
	Rational temp(newN, newD);
	return temp;
}
Rational Rational:: operator / (Rational & rhs)//division
{
	int newN = n * rhs.d; // subtructing the numbers and Creating a common denominator 
	int newD = d * rhs.n;
	Rational temp(newN, newD);
	return temp;
}

Rational::~Rational()//destructor
{
}
