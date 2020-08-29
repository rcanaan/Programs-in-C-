/*
Main Program

Name - Rinat Canaan ID 207744012
course - "workshop at C++"
exercise 1 question 3
description:
this program receives 3 circles, calculates the surface and the circumference of each circle.
in addition, it gets many points on the plane and calcultes if they are on, in or out of the circles.

*/
#include "Circle.h"
#include "Point.h"
using namespace std;

int main()
{
	Circle A, B, C;
	Point a, b;
	float r;
	int _x, _y, count1=0, count2=0, count3=0;
	cout << "enter the center point and radius of 3 circles" << endl;
	cin >> _x;	a.setX(_x);  cin >> _y;  a.setY(_y);	A.setCtr(a);	cin >> r;	A.setRad(r);//first circle - all the data
	cin >> _x;	a.setX(_x);  cin >> _y;  a.setY(_y);	B.setCtr(a);	cin >> r;	B.setRad(r);//second circle - all the data
	cin >> _x;	a.setX(_x);  cin >> _y;  a.setY(_y);	C.setCtr(a);	cin >> r;	C.setRad(r);//third circle - all the data
	
	cout << "area " << "A: " << A.circleS()<< "	" << "B: " << B.circleS() << "	" << "C: " << C.circleS() << endl;//area
	cout << "hekef " << "A: " << A.circleP() << "	" << "B: " << B.circleP() << "	" << "C: " << C.circleP() << endl;//hekef
	
	cin >> _x;	b.setX(_x);
	cin >> _y;	b.setY(_y);
	do 
	{
		
		if (A.inOnOut(b) != 1)
			count1++;///counting how many points
		if (B.inOnOut(b) != 1)
			count2++;///counting how many points
		if (C.inOnOut(b) != 1)
			count3++;///counting how many points
		cin >> _x;	b.setX(_x);
		cin >> _y;	b.setY(_y);

	} while ((_x||_y) != 0);//reading points until they are (0,0)
	cout << " num of points in circle	A:" << count1 << " B:" << count2 << " C:" << count3 << endl;
	
	
	
	//system("pause");
	return 0;
}
/*
enter the center point and radius of 3 circles
1 2 3
4 5 6
7 8 9
area A: 28.26   B: 113.04       C: 254.34
hekef A: 18.84  B: 37.68        C: 56.52
1 2
0 1
1 3
0 0
 num of points in circle        A:3 B:3 C:2
*/