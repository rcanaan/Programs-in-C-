#include "Student.h"

Student::Student() // defult initialization
{
	id = 0;
	strcpy_s(name, 20," ");
	strcpy_s(last, 20, " ");
	for (int i = 0; i < 5; i++)
		courses[i] = 'N';
	
}

Student::Student(int id, char * naMe, char * laSt, char c[5])
{
	setId(id); // initializing the current id to the received one
	setName(naMe);// initializing the current first name to the received one
	setLast(laSt);// initializing the current last name to the received one
	setCourses(c);// initializing the current courses to the received one
}

Student::~Student() // initializing student's info to defult values
{
	id = 0;
	strcpy_s(name, 20, " ");
	strcpy_s(last, 20, " ");
	for (int i = 0; i < 5; i++)
		courses[i] = 'N';
}

void Student::setId(int id)// setting received id
{
	this->id = id;
}

int Student::getId() const// returning current id
{
	return id;
}

void Student::setName(char * Name)// setting received fname
{
	strcpy_s(name,20 , Name);
}

char * Student::getName()// returning current fname
{
	return name;
}

void Student::setLast(char * Last)// setting received lname
{
	strcpy_s(last,20, Last);
}

char * Student::getLast()// returning current last name
{
	return last;
}

void Student::setCourses(char c[5])// setting received courses
{
	for (int i = 0; i < 5; i++)
	{
		courses[i] = c[i];
	}
}

char Student::getCourses(int i)// returning current course
{
	return courses[i];
}

void Student::print()// a function wich prints student's info 
{
	cout << "student's Id: " << id << endl;
	cout << "first name: " << name << endl;
	cout << "last name: " << last << endl;
	for (int i = 0; i < 5; i++)
	{
		if (courses[i] == 'Y')
			cout << "course num: " << (i + 1) << " Y" << endl;
		else
			cout << "course num: " << (i + 1) << " N" << endl;
	}
}
