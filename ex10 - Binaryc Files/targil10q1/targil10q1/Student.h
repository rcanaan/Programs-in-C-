#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student
{
	int id;
	char name[20];
	char last[20];
	char courses[5];
public:
	Student();//defult c-tor
	Student(int id, char*naMe, char* laSt, char c[5]); // copy c-tor
	~Student();// d-tor

	void setId(int id = 0); // setting received id
	int getId() const;// returning current id

	void setName(char* Name);// setting received name
	char* getName();// returning current name

	void setLast(char* Last);// setting received last name
	char* getLast();// returning current last name

	void setCourses(char c[5] /*=  "NNNNN"*/ );// setting received courses
	char getCourses(int); // returning current course

	void print();// a function wich prints student's info 
};