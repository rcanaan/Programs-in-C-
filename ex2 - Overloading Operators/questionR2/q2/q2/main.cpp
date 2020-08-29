
/*
important!
i didn't defined the "default constructor" at the end because it made me troubles and all the time
and a message popped and says that i can't defined at the main program a few types of "Date" because these can't be a few "default constructors"

Rinat Canaan ID 207744012
Course- "workshop at c++"
ex 2 question 2
this program gets different dates, changes them and checking for equality/inquality between them
*/


#include "Date.h"
#include <iostream>
using namespace std;
int main()
{
	Date r2, r3, r4;
	char slash;
	int d, m, y, choise ,numDays;
	cout << "Enter a date" << endl;
	cin >> d >> slash >> m >> slash >> y;
	Date r1(d, m, y);
	r1.print();
	/*cout << endl;*/

	cout << "what do you want to do" << endl;
	cin >> choise;
	while (choise != -1)
	{
		switch (choise)
		{
		case 1:
			cout << "enter a date" << endl;
			cin >> d >> slash >> m >> slash >> y;
			r1.setDate(d, m, y);
			r1.print();
			break;

		case 2:
			(++r1).print();
			break;

		case 3:
			(r1++).print();
			break;
		
		case 4:
			cout << "Enter #days" << endl;
			cin >> numDays;
			(r1 += numDays).print();
			break;

		case 5:
			cout << "Enter a date" << endl;
			cin >> d >> slash >> m >> slash >> y;
			/*Date */r2.setDate(d, m, y);
			if (r1 > r2)//checking if date r1 is bigger than date r2
				cout << ">: true" << endl;
			else
				cout << ">: false" << endl;
			break;

		case 6:
			cout << "Enter a date" << endl;
			cin >> d >> slash >> m >> slash >> y;
			/*Date*/ r3.setDate(d, m, y);
			if (r1 < r3)//checking if date r1 is smaller than date r2
				cout << "<: true" << endl;
			else
				cout << "<: false" << endl;
			break;

		case 7:
			cout << "Enter a date" << endl;
			cin >> d >> slash >> m >> slash >> y;
			/*Date*/ r4.setDate(d, m, y);
			if (r1 == r4)//checking if the dates are the same
				cout << "==: true" << endl;
			else
				cout << "==: false" << endl;
			break;
		}
		cout << "What do you want to do" << endl;
		cin >> choise;
	}




	system("pause");
	return 0;
 }
/*
Enter a date
-4/-3/1999
Error day
Error month
1/1/1999
what do you want to do
1
enter a date
18/3/2019
18/3/2019
What do you want to do
2
19/3/2019
What do you want to do
3
19/3/2019
What do you want to do
4
Enter #days
12
2/4/2019
What do you want to do
5
Enter a date
4/2/2019
>: true
What do you want to do
6
Enter a date
3/4/2019
<: true
What do you want to do
7
Enter a date
1/1/2020
==: false
What do you want to do
-1

*/