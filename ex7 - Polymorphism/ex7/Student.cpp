#include "Student.h"

Student::Student(int _id, const char* _Fname, const char* _Lname, int _Cnum)//constructor
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

const char* Student::get_Fname()
{
	return Fname;
}

const char* Student::get_Lname()
{
	return Lname;
}

int Student::get_Cnum()
{
	return Cnum;
}
