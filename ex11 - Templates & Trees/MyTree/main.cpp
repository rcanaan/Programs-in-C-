#include "SearchTree.h"
#include <iostream>
using namespace std;

int main()
{
	//Tree<char*> charTree;//ERROR _ ABSTRACT!!!!!
	SearchTree<int> myTree;
	//SearchTree<int> t2(myTree);
	myTree.add(5);
	myTree.add(6);
	myTree.add(8);
	myTree.add(2);

	cout << " in order on search tree\n";
	myTree.inOrder();
	cout << endl;

	if( myTree.search(8))
		cout <<  "true" << endl;
	else cout <<"false" << endl;

	return 0;
}
