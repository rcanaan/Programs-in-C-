/*
Rinat Canaan ID 207744012
Course- "workshop at c++"
ex 3 question 4
this program practicing on the String class.
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	/*std::*/string str;
	string str1 = "#!!@1234";
	/*std::*/getline(/*std::*/cin, str);//reading the string (with all the 4 words, including spaces)
	size_t found = str.find_first_of(" ");//looking for space- " " ("size_t- is instead of int)
	while (found != string::npos)//until the string hasn't come to its end
	{
		str[found] = '*';
		found = str.find_first_of(" ", found + 1);//heading on, looking for the next space
	}

	cout << str << endl;//printing for the first time, after the updating

	size_t lastWord = str.find_last_of("*");//earlier we used " ", but right now there are * between all the words
	str.replace(str.begin() + lastWord , str.end(), "#!!@1234");//replaces the last word with str1
	cout << str << endl;

	size_t word = str.find_first_of("*");
	str.erase(str.begin(), str.begin() + word + 1);//earasing the first word- from the stat til the *, and +1 for the space
	cout << str << endl;



	str.erase(str.begin(), str.begin() + word + 1);//earasing the second word word- from the stat til the *, and +1 for the space
	cout << str << endl;

	str.erase(str.begin(), str.begin() + word + 1);//will print only "#!!@1234"
	cout << str << endl;



	//system("pause");
	return 0;
}
/*
input:
aaa bbb ccc ddd
output:
aaa*bbb*ccc*ddd
aaa*bbb*ccc#!!@1234
bbb*ccc#!!@1234
ccc#!!@1234
!!@1234

aba sad bad had

aba*sad*bad*had
aba*sad*bad#!!@1234
sad*bad#!!@1234
bad#!!@1234
!!@1234
*/