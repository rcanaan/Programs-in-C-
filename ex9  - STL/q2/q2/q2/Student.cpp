#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

Student::Student(int _id, string _Fname, string _Lname, int _Cnum)//constructor
{
	id = _id;
	Fname = _Fname;
	Lname = _Lname;
	Cnum = _Cnum;

}

Student::~Student()//virtual destructor (in case therre is need to delete also the son(inherited) and not just the father)
{

}

int Student::get_ID()
{
	return id;
}

/*const*/ string Student::get_Fname()
{
	return Fname;
}

/*const*/ string Student::get_Lname()
{
	return Lname;
}

int Student::get_Cnum()
{
	return Cnum;
}
