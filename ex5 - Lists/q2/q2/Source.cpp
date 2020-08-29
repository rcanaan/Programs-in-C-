#include <iostream>
#include "List.h"
using namespace std;

//global functions
List merge(List  & lst1,List & lst2);//gets two devided lists, and returning a new merged List
List makeSet(List a);//turning the list into a group (deleliting repeated numbers)

int main()
{
	List lst1, lst2, mergedList;

	cout << "enter sorted values for the first list:" << endl;
	cin >> lst1;
	cout << "enter sorted values for the second list:" << endl;
	cin >> lst2;

	mergedList = merge(lst1, lst2);
	cout << "the new merged list: " << mergedList << endl;

	mergedList = makeSet(mergedList);
	cout << "the new merged set: " << mergedList << endl;

	//system("pause");
	return 0;
}
/*

enter sorted values for the first list:
1 2 3 4 0
enter sorted values for the second list:
2 3 4 5 6 7 8 8 8 8 8 8 8 0
the new merged list: 1 2 2 3 3 4 4 5 6 7 8
the new merged set: 1 2 3 4 5 6 7 8
*/


