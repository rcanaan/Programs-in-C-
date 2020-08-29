#include <iostream>
#include <string>
using namespace std;

class Student
{
	int  id;
	string  fname;
	string lname;
public:
	int getID(){return id;}
	void setID(int id) {this->id = id;}
	string getName(){return lname;}
	void setName(string n){lname = n;}

	Student(){}
	bool operator > (const Student& s);

};