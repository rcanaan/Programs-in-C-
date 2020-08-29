/*
Rinat Canaan ID 207744012
Course- "workshop at c++"
ex 3 question 2
this program defineds a class named "Vector" for executing an array with whole numbers.
*/
#include <iostream>
#include"Vector.h"
using namespace std;
//
//enum options
//{
//	stop, assignment, isEqual, mult, add, clear, delLast
//	//		0	1:=	   2:==	3:* 4:+ 5	6  
//};
//
//
//
//
//
//int main()
//{
//	Vector  v1(10), v2(10), v3;
//	int*pointer1 = v1.getData();        // keep the adress of first place in the array
//	int*pointer2 = v2.getData();
//
//	for (int i = 1; i <= 4; i++)
//	{
//		int*y = v1.getData();
//
//		v1.insert(i);
//		v2.insert(i + 4);
//	}
//
//
//	v1.set_data(pointer1);       // piont to the firsr data array adress
//	v2.set_data(pointer2);
//
//
//	int choice, val;
//	cout << "enter your choice 0-6\n"; cin >> choice;
//	while (choice)
//	{
//		switch (choice)
//		{
//		case assignment:; v3 = v1;
//
//			break;
//		case isEqual:   if (v1 == v2) cout << "v1==v2\n"; else cout << "v1!=v2\n";
//			break;
//		case mult:      cout << "v1*v2=" << v1 * v2 << endl;
//			break;
//		case add:       v3 = v1 + v2;
//				break;
//		case clear:     v1.clear();
//			break;
//		case delLast:   v2.delLast();
//			break;
//		default: cout << "ERROR";
//		}
//		cout << endl;
//		v1.print(); cout << endl; ; v2.print();    cout << endl;   v3.print();
//		cout << endl << "enter your choice 0-6\n"; cin >> choice;
//	}
//	system("pause");
//	return 0;
//}

#include<iostream>
#include "Vector.h"
using namespace std;
enum options
{
	stop, assignment, isEqual, mult, add, clear, delLast
	//      0   1:=    2:== 3:* 4:+ 5   6  
};

int main()
{
	Vector  v1(10), v2(10), v3;
	int*pointer1 = v1.get_data();        // keep the adress of first place in the array
	int*pointer2 = v2.get_data();


	for (int i = 1; i <= 4; i++)
	{
		int*y = v1.get_data();

		v1.insert(i);
		v2.insert(i + 4);
	}
	v1.set_data(pointer1);       // piont to the firsr data array adress
	v2.set_data(pointer2);
	int choice, val;
	cout << "enter your choice 0-6\n"; cin >> choice;
	while (choice)
	{
		switch (choice)
		{
		case assignment: v3 = v1;

			break;
		case isEqual:   if (v1 == v2) cout << "v1==v2\n"; else cout << "v1!=v2\n";
			break;
		case mult:      cout << "v1*v2=" << v1 * v2 << endl;
			break;
		case add:       v3 = v1 + v2;


			break;
		case clear:     v1.clear();
			break;
		case delLast:   v2.delLast();
			break;
		default: cout << "ERROR";
		}
		cout << endl;
		v1.print(); cout << endl; ; v2.print();    cout << endl;   v3.print();
		cout << endl << "enter your choice 0-6\n"; cin >> choice;
	}
	//system ("pause");
	return 0;
}