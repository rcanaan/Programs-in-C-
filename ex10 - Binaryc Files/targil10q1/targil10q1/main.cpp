/*

this program runs an academy that has only 5 courses,
it can add students remove them update thier courses status etc.
*/
#include"Student.h"
#include<iostream>
#include <string>
#include <fstream>
using std::cin;
using std::cout;
using namespace std;

enum choices { ADD = 1, DELETE, UPDATE, CHECK, PRINTS, PRINT_ALL, END = 0 };

bool checkId(int n, fstream &f)
{
	if (n != 0)
	{
		f.seekg((n - 1) * sizeof(Student), ios::beg);// going from the beginning of file to the student's place in the file wich is located according to his id number
		Student s;
		f.read((char*)&s, sizeof(Student)); // reading the student's details
		if (s.getId() != 0)// if the id in this place is not empty- it means that the student is already registered
			return true;// student already exists
	}
	return false; // student doesn't exist if his id==0- because at first all student's id is initialized to 0 
}

void addS(fstream &f)
{
	int _id;
	char ch;
	char fN[20], lN[20], c[5];
	cout << "enter student's ID, first name, and last name" << endl; // request for student's info
	cin >> _id >> fN >> lN;// receiving the student's info
	if (checkId(_id, f) == true) // if student already exist
		cout << "ID already exists" << endl; // printing an apropriate message
	else
	{
		cout << "enter 'Y' or 'N' according to the courses you study " << endl;
		for (int i = 0; i < 5; i++) // receiving the courses the student is studying
		{
			cin >> ch;
			c[i] = ch;
		}
		Student newS(_id, fN, lN, c); // making a new veraible of type 'Student'
		f.seekp((_id - 1) * sizeof(Student), ios::beg); // searching from the begginning of file, the place that the student should be in- according to his id number
		f.write((char*)&newS, sizeof(Student)); // writing his details in the file
	}
}

void deleteS(int n, fstream &f)
{
	if (checkId(n, f))
	{
		Student s; // defult c-tor will initialize all values of student to 0
		f.seekp((n - 1) * sizeof(Student), ios::beg);
		f.write((char*)&s, sizeof(Student)); // entering the "zeroed" student to the place if the student we want to delete
	}
	else
		throw "student does not exist";
}
void updateS(int n, fstream &f)
{
	char ch, c[5]; // cteating tmp veraibles
	Student s;
	if (checkId(n, f)) // if the student exist
	{
		cout << "enter 'Y' or 'N' according to the courses you study " << endl; // we'll ask the user to enter the courses he studies
		for (int i = 0; i < 5; i++) // receiving the courses the student is studying
		{
			cin >> ch;
			c[i] = ch;
		}
		f.seekg((n - 1) * sizeof(Student), ios::beg);// searching from start of file- the place of student in the file
		f.read((char*)&s, sizeof(Student));// reading his details into student s
		s.setCourses(c); // and resetting his courses by adding the new courses int his courses list
		f.seekg((n - 1) * sizeof(Student), ios::beg);// searching for his place in file again
		f.write((char*)&s, sizeof(Student));// and writing his updated info- to his place in file
	}
	else 
		throw "student does not exist"; // if the student is not in the file
}

bool isSigned(int n, int i, fstream &f)
{
	Student s;
	if (i <= 4 && i > 0)// if the course number is valid
	{
		if (checkId(n, f)) // and if the student does exist
		{
			f.seekg((n - 1) * sizeof(Student), ios::beg);// searching from start of file- the place of student in the file
			f.read((char*)&s, sizeof(Student));// reading his details into student s
			if (s.getCourses(i) == 'Y')// if the student does study this specific course
				return true; // the function will return 'true'
		}
		return false; // if he doesn't study this course - it willl return false
	}
	else
		throw "there is no such a course"; // if index number-i is not valid
}

void printS(int n, fstream &f)
{
	Student s;
	if (checkId(n, f))// if the student alraedy exist in file
	{
		f.seekg((n - 1) * sizeof(Student), ios::beg);// searching from start of file- the place of student in the file
		f.read((char*)&s, sizeof(Student));// reading his details into student s
		s.print();// calling the student's print function in order to print his details
	}
	else
		throw "student does not exist";// if the student is not in the file
}

void printSigned(int cIndex, fstream &f)
{
	if (cIndex < 0 || cIndex>4)// if the index of courses is not valid
		throw "there is no such a course";
	for (int i = 0; i < 100; i++)// going through all of the 100 students in the file
	{
		if (checkId(i, f))// and checking if the students are initialized-exist
		{
			Student s;
			f.seekg((i - 1) * sizeof(Student), ios::beg);// searching from start of file- the place of student in the file
			f.read((char*)&s, sizeof(Student));// reading his details into student s
			if (s.getCourses(cIndex) == 'Y') // if the current student does study the specific course
				cout << s.getName() << " " << s.getLast() << endl; // we'll print his first and last name
		}
	}
}

void beginFile(const char* f)
{
	Student s;
	ofstream file(f);
	if (!file)
		throw "cannot openn file!";
	for (int i = 0; i < 100; i++)
	{
		file.write((char*)&s, sizeof(s));
	}
}

int main()
{
	try// in case of thrown exceptions
	{
		//fstream Students("Students1.txt", ios::in | ios::out); // opening a binary file
		//Students.open("Students1.txt", ios::in | ios::out);
		//if (!Students)
		//	throw "file can not be opened"; // if file could not be opened

		fstream Students;// .open(ostream | istream);
		Students.open("Students1.dat", ios::in | ios::out);
		try {
			beginFile("Students1.dat");
		}
		catch (char * s)
		{
			cout << s;
		}

		int choice;  // requesting a number
		cout << "enter 1 to add a new student" << endl;
		cout << "enter 2 to delete existing student" << endl;
		cout << "enter 3 to update a student's courses" << endl;
		cout << "enter 4 to check the status of a student's course" << endl;
		cout << "enter 5 to print details of a student" << endl;
		cout << "enter 6 to print all students in this course" << endl;
		cout << "enter 0 to exit" << endl;
		cin >> choice; // receiving the number

		while (choice != 0) // zero=end of program 
		{
			switch (choice)
			{
			case ADD:
				try // in case of thrown exceptions
				{
					addS(Students); // adding a student to the file
				}
				catch (const char* str)// catching the thrown exception
				{
					cout << str << endl;
				}
				break;

			case DELETE:
				int _id;
				cout << "enter student ID:" << endl; // receiving the student number
				cin >> _id;
				try//  in case of thrown exceptions
				{
					deleteS(_id, Students);// deleting the student number from the file
				}
				catch (const char* str) // catching the thrown exception
				{
					cout << str << endl;
				}
				break;

			case UPDATE:
				try //  in case of thrown exceptions
				{
					int _id;
					cout << "enter student ID:" << endl;
					cin >> _id;              // receiving the student number
					updateS(_id, Students); // updating the courses wich the student does study
				}
				catch (const char* str) // catching the thrown exception
				{
					cout << str << endl;
				}
				break;
				
			case CHECK:
				try//  in case of thrown exceptions
				{
					int id, index;
					cout << "enter student ID:" << endl;
					cin >> id;  // receiving the student number
					cout << "enter course number:" << endl;
					cin >> index;  // receiving the number of course
					if (isSigned(id, index, Students)) // checking wether or not the student is signed to this spesific course
						cout << "student is signed to this course" << endl; //if he is signed to the course
					else
						cout<< "student isn't signed to this course" << endl;//if he isn't signed to the course
				}
				catch (const char* str) // catching the thrown exception
				{
					cout << str << endl;
				}
				break;

			case PRINTS:
				try//  in case of thrown exceptions
				{
					int _id;
					cout << "enter student ID:" << endl;
					cin >> _id;   //receiving the student number
					printS(_id, Students); // printing the students
				}
				catch (const char* str)// catching the thrown exception
				{
					cout << str << endl;
				}
				break;

			case PRINT_ALL:
				try//  in case of thrown exceptions
				{
					int index;
					cout << "enter course number:" << endl;
					cin >> index;//receiving the student number
					printSigned(index, Students);// printing all students how are signed to a specific course
				}
				catch (const char* str)// catching the thrown exception
				{
					cout << str << endl;
				}
				break;

			default: cout << "ERROR" << endl;// in case of receiving a number that is not between 0-6
				break;
			}
			// requesting a number
			cout << "enter 1 to add a new student" << endl;
			cout << "enter 2 to delete existing student" << endl;
			cout << "enter 3 to update a student's courses" << endl;
			cout << "enter 4 to check the status of a student's course" << endl;
			cout << "enter 5 to print details of a student" << endl;
			cout << "enter 6 to print all students in this course" << endl;
			cout << "enter 0 to exit" << endl;
			
			cin >> choice; // receiving a number
			Students.clear();
		}
	}
	catch (const char* str)// catching the thrown exception
	{
		cout << str << endl;
	}
	return 0;
}

/*
Output:
enter 1 to add a new student
enter 2 to delete existing student
enter 3 to update a student's courses
enter 4 to check the status of a student's course
enter 5 to print details of a student
enter 6 to print all students in this course
enter 0 to exit
1
enter student's ID, first name, and last name
1
avi
levi
enter 'Y' or 'N' according to the courses you study
YYYNN
enter 1 to add a new student
enter 2 to delete existing student
enter 3 to update a student's courses
enter 4 to check the status of a student's course
enter 5 to print details of a student
enter 6 to print all students in this course
enter 0 to exit
1
enter student's ID, first name, and last name
2
avram
cohen
enter 'Y' or 'N' according to the courses you study
NNYYY
enter 1 to add a new student
enter 2 to delete existing student
enter 3 to update a student's courses
enter 4 to check the status of a student's course
enter 5 to print details of a student
enter 6 to print all students in this course
enter 0 to exit
1
enter student's ID, first name, and last name
3
shalm
vaitz
enter 'Y' or 'N' according to the courses you study
NNNYY
enter 1 to add a new student
enter 2 to delete existing student
enter 3 to update a student's courses
enter 4 to check the status of a student's course
enter 5 to print details of a student
enter 6 to print all students in this course
enter 0 to exit
2
enter student ID:
1
enter 1 to add a new student
enter 2 to delete existing student
enter 3 to update a student's courses
enter 4 to check the status of a student's course
enter 5 to print details of a student
enter 6 to print all students in this course
enter 0 to exit
5
enter student ID:
2
student's Id: 2
first name: avram
last name: cohen
course num: 1 N
course num: 2 N
course num: 3 Y
course num: 4 Y
course num: 5 Y
enter 1 to add a new student
enter 2 to delete existing student
enter 3 to update a student's courses
enter 4 to check the status of a student's course
enter 5 to print details of a student
enter 6 to print all students in this course
enter 0 to exit
3
enter student ID:
2
enter 'Y' or 'N' according to the courses you study
YYYYY
enter 1 to add a new student
enter 2 to delete existing student
enter 3 to update a student's courses
enter 4 to check the status of a student's course
enter 5 to print details of a student
enter 6 to print all students in this course
enter 0 to exit
6
enter course number:
3
avram cohen
shalm vaitz
enter 1 to add a new student
enter 2 to delete existing student
enter 3 to update a student's courses
enter 4 to check the status of a student's course
enter 5 to print details of a student
enter 6 to print all students in this course
enter 0 to exit
4
enter student ID:
2
enter course number:
3
student is signed to this course
enter 1 to add a new student
enter 2 to delete existing student
enter 3 to update a student's courses
enter 4 to check the status of a student's course
enter 5 to print details of a student
enter 6 to print all students in this course
enter 0 to exit
4
enter student ID:
3
enter course number:
3
student is signed to this course
enter 1 to add a new student
enter 2 to delete existing student
enter 3 to update a student's courses
enter 4 to check the status of a student's course
enter 5 to print details of a student
enter 6 to print all students in this course
enter 0 to exit
4
enter student ID:
3
enter course number:
2
student isn't signed to this course
enter 1 to add a new student
enter 2 to delete existing student
enter 3 to update a student's courses
enter 4 to check the status of a student's course
enter 5 to print details of a student
enter 6 to print all students in this course
enter 0 to exit

*/