#include "MA.h"
#include "BA.h"
#include <iostream>
using namespace std;



MA::MA(int _id,  const char* _Fname, const char* _Lname, int _Cnum, int* _grades, bool _DoSearch) : BA(_id, _Fname, _Lname, _Cnum, _grades)
{
	DoSearch = _DoSearch;
}

MA::~MA()
{
	//delete[] grades;
}

bool MA::milga()//"pure virtual".execution at each inherited class. checks if the student eligible for the scolarship. 
{
//	float aver = average();
	if ((this->average() > 90) && (this->Cnum >= 7) && (this->DoSearch == true))//if all the conditions are fullfilled
		return true;
	return false;
}

void MA::print()
{

	cout << "ID: " << id << endl;
	cout << "first name: " << get_Fname() << endl;
	cout << "last name: " << get_Lname() << endl;
	cout << "num courses: " << Cnum << endl;
	cout << "grades: ";
	for (int i = 0; i < Cnum; i++)
		cout << grades[i] << " ";
	cout << endl;
	cout << "research: ";
	if (DoSearch == true)
		cout << "yes" << endl;
	else
		cout << "no" << endl;

}
