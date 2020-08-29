#pragma once
#include "Student.h"
#include <string>
#include <iostream>
using namespace std;
//inherited class from Student. represents the PDH - ("doctorat")
class PHD :public Student
{
protected:
	int n_week;//num hours of working at research

public:
	PHD(int _id, /*const*/ string _Fname, /*const*/ string _Lname, int _Cnum, int Nweek);//constructor
	~PHD();//destructor

	int getNweek();
	bool Dosearch();// { return false; }
	int getCnum();// { return Cnum; }
	virtual bool milga();//"pure virtual".execution at each inherited class. checks if the student eligible for the scolarship. 
	virtual void print();//"pure virtual" execution at each inherited class	.printing the student's data
	virtual string studyType(); //{ return "PHD"; }
};

