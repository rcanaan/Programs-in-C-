#include "Student.h"

bool Student::operator > (const Student& s)
{
	if (this->lname == s.lname)
		return this->fname > s.fname;
	else
		return this->lname > s.lname;
}