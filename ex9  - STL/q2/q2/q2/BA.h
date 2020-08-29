#pragma once
#include "Student.h"
#include <string>
#include <iostream>
using namespace std;
//inherited class from Student. represents the BA- bachelor's degree ("toar reshon")
class BA : public Student
{
protected:
	int* grades;//pointer to grades
	int Sgrades;//the suze of the grades vector

public:
	BA(int _id, string _Fname, string _Lname, int _Cnum, int* _grades);//constructor
	~BA();//destructor
	int getNweek() { return 0; }
	bool Dosearch() { return false; }
	
	int getCnum() { return Cnum; }
	void setGrades(int grade);//setting the grades into the vec
	int getGrades(int index);//getting the grade

	virtual	float average();//calculating the average
	virtual bool milga();//"pure virtual".execution at each inherited class. checks if the student eligible for the scolarship. 
	virtual void print();//"pure virtual" execution at each inherited class	.printing the student's data
	virtual string studyType() { return "BA"; }
};
