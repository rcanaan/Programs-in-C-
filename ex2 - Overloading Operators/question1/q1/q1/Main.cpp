/*
Rinat Canaan ID 207744012
Course- "workshop at c++"
ex 2 question 1
this program defineds new operators on rational numbers.
*/
#include "Rational.h"
#include <cstring>
using namespace std;
int main()
{
	int n1, n2, m1, m2;
	char slash;

	cout << "Enter two rational numbers" << endl;
	cout << "a: ";	cin >> n1 >> slash >> n2;	Rational firstN(n1, n2);//setting first number
	cout << "b: ";	cin >> m1 >> slash >> m2;	Rational secondN(m1, m2);//seting the second number

	cout << "b-a: "; (secondN - firstN).print();
	cout << endl; //b-a

	cout << "a!=b: ";//if a is different than b
	if (secondN != firstN)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	cout << "a<b: "; //if b is bigger than a
	if (firstN < secondN)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	cout << "a>b: "; //if a is bigger than b
	if (firstN > secondN)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	cout << "a>=b: ";//if a is bigger or equale than b
	if (firstN >= secondN)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	cout << "a++: ";	(firstN++).print();		cout << endl;//printing a++
	cout << "--a: ";	(--firstN).print();		cout << endl;//printing --a
	cout << "a--: ";	(firstN--).print();		 cout << endl;//printing a--

	secondN = firstN;//b=a

	cout << "b-a: "; (secondN - firstN).print();
	cout << endl; //b-a

	cout << "b/a: "; (secondN / firstN).print();
	cout << endl; /// b/a

	cout << "a!=b: ";
	if (secondN != firstN)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	cout << "a<b: ";
	if (firstN < secondN)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	cout << "a>=b: ";
	if (firstN >= secondN)
		cout << "true" << endl;
	else
		cout << "false" << endl;


	//system("pause");
	return 0;


}
/*
Enter two rational numbers
a: 2/3
b: 3/4
b-a: 1/12
a!=b: true
a<b: true
a>b: false
a>=b: false
a++: 2/3
--a: 2/3
a--: 2/3
b-a: 0
b/a: 1
a!=b: false
a<b: false
a>=b: true

Enter two rational numbers
a: 6/7
b: 8/9
b-a: 2/63
a!=b: true
a<b: true
a>b: false
a>=b: false
a++: 6/7
--a: 6/7
a--: 6/7
b-a: 0
b/a: 1
a!=b: false
a<b: false
a>=b: true
*/