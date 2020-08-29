#include "PHD.h"
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

PHD::PHD(int _id, /*const*/ string _Fname, /*const*/ string _Lname, int _Cnum, int Nweek) :Student(_id, _Fname, _Lname, _Cnum)//constructor
{
	n_week = Nweek;
}

PHD::~PHD()
{
}

int PHD::getNweek()
{
	return n_week;
}

bool PHD::Dosearch()
{
	return true;
}

int PHD::getCnum()
{
	return Cnum;
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

string PHD::studyType()
{
	return "PHD";
}


