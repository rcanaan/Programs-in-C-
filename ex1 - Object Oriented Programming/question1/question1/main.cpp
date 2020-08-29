/*
Main Program

Name - Rinat Canaan ID 207744012
course - "workshop at C++"
exercise 1 question 1
description: 
this program will has class for rational numbers. 
it will get two numbers and will print a message if they are equale and if they are not it will also print the numbers before the decreasing them.
*/
#include "Rational.h"
using namespace std;

int main()
{
	Rational r1, r2;
	int numer, denom;//these 2 variables wil get the numbers
	char slash;//will get the "/"
	cout << "enter two rational numbers" << endl;
	cin >> numer;
	r1.setNumer(numer);//setting the mone because it is private
	cin >> slash;
	cin >> denom;
	r1.setDenom(denom);//setting the mechane because it is private

	cin >> numer;
	r2.setNumer(numer);//setting the mone because it is private
	cin >> slash;
	cin >> denom;
	r2.setDenom(denom);//setting the mechane because it is private

	if (r1.equal(r2) == true)
		cout << "equal" << endl;
	else
	{
		cout << "different ";
		r1.print();
		cout << " ";
		r2.print();
		cout << endl;
	}
	system("pause");
	return 0;
}
/*
enter two rational numbers
1/2
58/116
equal

enter two rational numbers
2/3
3/4
different 2/3 3/4
*/
