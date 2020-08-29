/*
Rinat Canaan ID 207744012
Course- "workshop at c++"
ex 5 question 1
This program implements the data structur -List and its functions 
*/


#include <iostream>
#include "List.h"
using namespace std;

	int main()
	{
		List lst;
		int choice, val;
		cout << "enter the list values\n";
		cin >> lst;
		cout << "choose 0-2\n";
		cin >> choice;
		while (choice)
		{
			try //if there is any execptions
			{
				switch (choice)
				{
				case 1:cout << "enter a value to insert\n";
					cin >> val;
					lst.insert(val);
					break;
				case 2:cout << "enter a value to remove\n";
					cin >> val;
					try {
						lst.remove(val);
					}
					catch (char * msg)
					{
						cout << msg << endl;
					}
					break;
				default:cout << "ERROR\n";
				}
			}
			catch (const char * str)
			{
				cout << str << endl;
			}
			cout << lst << endl;
			cout << "choose 0-2\n";
			cin >> choice;
		}
	
	




	system("pause");
	return 0;
}
	/*
	enter the list values
1 3 5 7 9 0
choose 0-2
1
enter a value to insert
2
1 2 3 5 7 9
choose 0-2
1
enter a value to insert
4
1 2 3 4 5 7 9
choose 0-2
2
enter a value to remove
2
1 3 4 5 7 9
choose 0-2
2
enter a value to remove
7
1 3 4 5 9
choose 0-2
1
enter a value to insert
6
1 3 4 5 6 9
choose 0-2
0
	*/