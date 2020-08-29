#include "PHD.h"
#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

PHD::PHD(int _id, const char* _Fname, const char* _Lname, int _Cnum, int Nweek) :Student(_id, _Fname, _Lname, _Cnum)//constructor
{
	n_week = Nweek;
}

PHD::~PHD()
{
}

bool PHD::milga()
{
	if ((Cnum == 2) && (n_week >= 25))
		return true;
	return false;
}

void PHD::print()
{
	cout << "ID: " << id << endl;
	cout << "first name: " << get_Fname() << endl;
	cout << "last name: " << get_Lname() << endl;
	cout << "num courses: " << Cnum << endl;
	cout << "hours: " << n_week << endl;
}
