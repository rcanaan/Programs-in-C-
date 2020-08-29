#include "BA.h"
#include "Student.h"
#include <iostream>
using namespace std;

BA::BA(int _id, const char* _Fname, const char* _Lname, int _Cnum, int* _grades):Student(_id, _Fname, _Lname, _Cnum)//constructor
{
	grades = new int[_Cnum];//the size will be accroding the num courses
	for (int i = 0; i < _Cnum; i++)
		grades[i] = _grades[i];//copies the grades
	Sgrades = _Cnum;// updating the grade size to be like the number of courses
	
}

BA::~BA()
{
	delete[]grades;
}

void BA::setGrades(int grade)//setting the grades into the vec
{
	for (int i = 0; i < Sgrades; i++)
		grades[i] = grade;
}

int BA::getGrades(int index)//returning a specific grade
{
	return grades[index];
}

float BA::average()//calculating the average
{
	float sum = 0;
	float average = 0;
	for (int i = 0; i < Cnum; i++)
		sum = sum + grades[i];
	average = sum / Cnum;//calculating the average
	return average;
//	return (sum / Cnum);
}

bool BA::milga()//"pure virtual".execution at each inherited class. checks if the student eligible for the scolarship. 
{
	//int av = average();
	if ((Cnum >= 10) && (average() > 95))
		return true;
	return false;
}

void BA::print()//"pure virtual" execution at each inherited class	.printing the student's data
{
	cout << "ID: " << id << endl;
	cout << "first name: " << get_Fname() << endl;
	cout << "last name: " << get_Lname() << endl;
	cout << "num courses: " << Cnum << endl;
	cout << "grades: ";
	for (int i = 0; i < Cnum ; i++)
		cout << grades[i] << " ";
	cout << endl;
}
