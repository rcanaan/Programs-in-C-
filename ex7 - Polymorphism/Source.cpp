//name:hodaya rachel bismut i.d:322269333
#include<iostream>
#include"BA.h"
#include"MA.h"
#include"PHD.h"
#include"Student.h"
#include<vector>
using namespace std;
void printOnly(vector<Student*> v)
{
	for (int i = 0; i < 7; i++)
	{
		if (v[i]->milga())
			v[i]->print();
	}
}
int main()
{
	vector<Student*> v(7); // vector of student pointrs with 7 places
	int arr[4][10] = { {90,100,90},{100,100,90,100,90,100,90,100,90,100},{90,100,90,100,90,100,90},{90,100,90,100,90,100,90} }; // arrays of grades
	// create students
	BA BA1(123, "avraham", "abe", 3, arr[0]); // create students and insert them into vector (pointrs to them)
	v[0] = &BA1;
	BA BA2(234, "yitzhak", "avrahamson", 10, arr[1]);
	v[1] = &BA2;
	MA MA1(345, "yaacov", "jacobson", 7, arr[2], 0);
	v[2] = &MA1;
	MA MA2(456, "sara", "emanu", 7, arr[3], 1);
	v[3] = &MA2;
	PHD PHD1(567, "rivka", "imanu", 1, 30);
	v[4] = &PHD1;
	PHD PHD2(678, "rachel", "jacobs", 2, 20);
	v[5] = &PHD2;
	PHD PHD3(789, "leah", "jacobs", 2, 30);
	v[6] = &PHD3;
	//vector<Student> v1;
	printOnly(v);
	system("pause");
	return 0;
}
/*ID: 234
first name : yitzhak
last name: avrahamson
num courses: 10
grades: 100 100 90 100 90 100 90 100 90 100
ID: 456
first name : sara
last name: emanu
num courses: 7
grades: 90 100 90 100 90 100 90
research: yes
ID: 789
first name : leah
last name: jacobs
num courses: 2
hours: 30
Press any key to continue . . .*/