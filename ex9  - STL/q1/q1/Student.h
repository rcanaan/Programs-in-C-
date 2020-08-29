#pragma once
//an abstract class, can't create by itself an object
#include <string>

class Student
{
protected:
	int id;//id number 
	const char* Fname;//first name
	const char* Lname;//last name
	int Cnum;//num of courses

public:
	Student(int _id, const char* _Fname, const char* _Lname, int _Cnum);//constructor
	virtual ~Student();//virtual destructor (in case therre is need to delete also the son(inherited) and not just the father)

	int get_ID();
	const char* get_Fname();
	const char* get_Lname();
	int get_Cnum();

	virtual bool milga() = 0;//"pure virtual".execution at each inherited class. checks if the student eligible for the scolarship. 
	virtual void print() = 0;//"pure virtual" execution at each inherited class	.printing the student's data
	//virtual string studyType() = 0;

};