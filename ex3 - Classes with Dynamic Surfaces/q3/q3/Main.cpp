/*
Rinat Canaan ID 207744012
Course- "workshop at c++"
ex 3 question 3
this program defining 2 classes- Point and Polygon, and calculate the circumference of the polygon.
*/
#include <iostream>
#include"Polygon.h"
#include "Point.h"
using namespace std;
int main()
{

	int x, y, n;
	int circumference; 
	Point A;
	cout << "num of vertexes:" << endl;
	cin >> n;//the num of Vertexes
	
	if (n < 3)
	{
		cout << "ERROR" << endl;
		cin >> n;
	}
	Polygon P(n);//initializing Polygon
	cout << "x, y:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;//getting the points
		A.setX(x);	A.setY(y);//initializing it into Point type 
		P.setPoli(A);//inserting the points into the "poly" array
	}
	circumference = P.circu();//finding the circu
	cout << circumference << endl;

	system("pause");
	return 0;
}

/*
num of vertexes:
4
x, y:
1 2 3 4 5 6 7 8
21
*/



