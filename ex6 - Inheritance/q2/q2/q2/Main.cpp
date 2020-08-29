/*
Rinat Canaan ID 207744012
Course- "workshop at c++"
ex 6 question 2
This program implements inheritence between to classes- 
the father class "Polygon" and the inheritend classes- "Rectangle" and "Triangle"
*/
#include "Polygon.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <iostream>
using namespace std;
int main()
{
	int n1, n2,a1,b1 ,c1, a2,b2,c2;
	cout << "enter number of sides for polygon 1:" << endl;//for the first Polygon
	cin >> n1;
	Poly P1(n1);
	if ((n1 == 3) || (n1 == 4))//if this is triangle or rectangle
	{
		cout << "enter sides for polygon:" << endl;//for the first polygon
		if (n1 == 3)
		{
			cin >> a1 >> b1 >> c1;
			Triangle T1(a1, b1, c1);//creating the triangle

			cout <<	"enter number of sides for polygon 2:" << endl;
			cin >> n2;
			if (n2 == 3)//if the second polygon is also a triangle
			{
				cout << "enter sides for polygon:" << endl;
				cin >> a2 >> b2 >> c2;
				Triangle T2(a2, b2, c2);//creating the triangle

				if (T1 == T2)	//if all the data is equale
					cout << "equal" << endl;
				else
					cout << "not equal" << endl;

			}
			else
				cout << "not equal" << endl;
		}

		if (n1 == 4)//in case its a rectangle
		{
			cin >> a1 >> b1;
			Rectangle R1(a1, b1);//creating the triangle

			cout << "enter number of sides for polygon 2:" << endl;
			cin >> n2;
			if (n2 == 4)//if the second polygon is also a triangle
			{
				cout << "enter sides for polygon:" << endl;
				cin >> a2 >> b2;
				Rectangle R2(a2, b2);//creating the triangle

				if (R1 == R2)	//if all the data is equale
					cout << "equal" << endl;
				else
					cout << "not equal" << endl;

			}
			else
				cout << "not equal" << endl;

		}
	}

	else//in case it is another type of Polygon
	{
		cout << "enter number of sides for polygon 2:" << endl;
		cin >> n2;
		Poly P2(n2);
		if (P1 == P2)
			cout << "equal" << endl;
		else
			cout << "not equal" << endl;
		
	}
	

	//system("pause");
	return 0;
}
/*
enter number of sides for polygon 1:
3
enter sides for polygon:
1 3 5
enter number of sides for polygon 2:
3
enter sides for polygon:
3 2 1
not equal


enter number of sides for polygon 1:
3
enter sides for polygon:
1 4 8
enter number of sides for polygon 2:
3
enter sides for polygon:
1 1 11
equal

enter number of sides for polygon 1:
6
enter sides for polygon:
1 2 3 4 5 6
enter number of sides for polygon 2:
6
enter sides for polygon:
1 1 1 1 1 16
equal


enter number of sides for polygon 1:
4
enter sides for polygon:
2 4
enter number of sides for polygon 2:
6
not equal
*/