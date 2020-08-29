#pragma once

#include "Student.h"
#include <string>
//inherited class from Student. represents the PDH - ("doctorat")
class PHD :public Student
{
protected:
	int n_week;//num hours of working at research

public:
	PHD(int _id, const char* _Fname, const char* _Lname, int _Cnum, int Nweek);//constructor
	~PHD();//destructor
	virtual bool milga();//"pure virtual".execution at each inherited class. checks if the student eligible for the scolarship. 
	virtual void print();//"pure virtual" execution at each inherited class	.printing the student's data
	
};
