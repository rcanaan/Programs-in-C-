#pragma once
//an abstract class, can't create by itself an object
#include <string>
#include <iostream>
using namespace std;
class Student
{
protected:
	int id;//id number 
	/*const*/ string Fname;//first name
	/*const*/ string Lname;//last name
	int Cnum;//num of courses

public:
	Student(int _id, string _Fname, string _Lname, int _Cnum);//constructor
	virtual ~Student();//virtual destructor (in case therre is need to delete also the son(inherited) and not just the father)

	int get_ID();
	/*const*/string get_Fname();
	/*const*/ string get_Lname();
	int get_Cnum();
	virtual int getNweek() = 0;
	virtual bool Dosearch() = 0;
	virtual int getCnum() = 0;


	virtual bool milga() = 0;//"pure virtual".execution at each inherited class. checks if the student eligible for the scolarship. 
	virtual void print() = 0;//"pure virtual" execution at each inherited class	.printing the student's data

	virtual string studyType() = 0;//"pure virtual" execution at each inherited class	.returning the student's type
};

