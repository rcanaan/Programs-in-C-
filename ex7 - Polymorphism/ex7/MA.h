#pragma once
#include "Student.h"
#include "BA.h"
//inherited class from BA (MA->BA->Student). represents the MA- master's degree ("toar sheni")
class MA : public BA
{
protected:
	bool DoSearch;//does the student makes a research or not

public:
	MA(int _id, const char* _Fname, const char* _Lname, int _Cnum, int* _grades, bool DoSearch);
	~MA();

	virtual bool milga();//"pure virtual".execution at each inherited class. checks if the student eligible for the scolarship. 
	virtual void print();//"pure virtual" execution at each inherited class	.printing the student's data
};

