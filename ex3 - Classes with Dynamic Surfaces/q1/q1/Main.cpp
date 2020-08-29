/*
Rinat Canaan ID 207744012
Course - "workshop at c++"
ex 3 question 1
this program builds and definds the different functions of the "String" class
*/
#include <iostream>
#include <cstring>
#include "String.h"
using namespace std;
int main()
{
	char a[100], b[100];//definding the string a and b
	int n;//represent the wanted index
	cout << "Enter strings:" << endl;
	cin >> a >> b >> n;
	String A(a);	String B(b);
	A > B;//printing
	A = B;
	A < B;

	String  C = B.insert(n, a);//the combined string
	if (n <= strlen(a))//if the user wants to put from an index which that not exist
		C.print_str();//printing the renew string
	


	//system("pause");
	return 0;
}
/*
Enter strings
Hello
World
4
a<b
WorlHellod

Enter strings:
Canaan
Rinat
5
a<b
RinatCanaan
*/