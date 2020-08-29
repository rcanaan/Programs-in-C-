/*
Rinat Canaan ID 207744012
Course- "workshop at c++"
ex 7
this program runs a scolership programing for studenst for -BA, MA, and PHD degrees.
It uses polymorphism and virtual classes
*/
#include <iostream>
using namespace std;
#include "Student.h"
#include "MA.h"
#include "BA.h"
#include "PHD.h"
#include <vector>//this liberary helps us define easily a data stucture - such as vector

void print(vector<Student*> vec);

int main()
{
	vector <Student*> students;// creating an empty vector "students", and its type is Student

	int vec1[3] = { 90, 100, 90 };//grades of student at BA
	int vec2[10] = { 100, 100, 90, 100, 90, 100, 90, 100, 90, 100 }; ///grades of student at MA     
	int vec3[7] = { 90, 100, 90, 100, 90, 100, 90 }; ///grades of student at PDH
	//the student will be created (as the "new" command  the constructors) and will be sent to the vectors at the same time
	students.push_back(new BA(123, "abe", "avraham", 3, vec1));           
	students.push_back(new BA(234, "yitzhak", "avrahamson", 10, vec2));   
	students.push_back(new MA(345, "yaacov", "jacobson", 7, vec3, 0));    
	students.push_back(new MA(456, "sara", "emanu", 7, vec3, 1));        
	students.push_back(new PHD(567, "rivka", "imanu", 1, 30));           
	students.push_back(new PHD(678, "rachel", "jacobs", 2, 20));         
	students.push_back(new PHD(789, "leah", "jacobs", 2, 30));           
	
	print(students);//printing the students which can get the scolarship
	
	
	
	
	//system("pause");
	return 0;
}
void print(vector<Student*> vec)
{
	for (int i = 0; i < 7; i++)
	{
		if (vec[i]->milga())
			vec[i]->print();
	}
}
/*

ID: 234
first name: yitzhak
last name: avrahamson                                                                                            
num courses: 10
grades: 100 100 90 100 90 100 90 100 90 100
ID: 456
first name: sara
last name: emanu
num courses: 7
grades: 90 100 90 100 90 100 90
research: yes
ID: 789
first name: leah
last name: jacobs
num courses: 2
hours: 30
Press any key to continue . . .

*/