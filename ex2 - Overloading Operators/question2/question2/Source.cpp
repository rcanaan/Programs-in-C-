/* Avishag chtrit  ID:211525795
Targil 3 Question 3
this program receives points of a polindrom
and calculates the Scope of it*/

#include <iostream>
#include "Point.h"
#include "Poli.h"
using namespace std;

int main()
{
	int x, y;
	Point A;               //create Point
	int n;                 // the nm of points
	cin >> n;
	if (n < 0)
	{
		cout << "ERROR" << endl;
		//system("pause");
		return 0;
	}

	Poli R(n); // create the Poli with the num of points(n)

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;                // get point from user
		A.setX(x); A.setY(y);    // enter point cordinates to class point
		R.setPoli(A);            // insert the points to the points array
	}
	cout << R.hekef(R) << endl;  // printing the hekef

	system("pause");
	return 0;
}
/*
Output:
4
0 0 0 2 2 2 2 0
8
Press any key to continue . . .

-3
ERROR
Press any key to continue . . .

3
10 10 10  14 13 10
12
Press any key to continue . . .
*/