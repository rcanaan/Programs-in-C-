/*
Rinat Canaan 207744012
exe 9
this program uses the 7's classes (student,BA,MA,PHD) with stl algorithims, and vector. 

*/

#include "Student.h"
#include "MA.h"
#include "BA.h"
#include "PHD.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

enum optios
{
	stop,	//ending program
	add_New_Student,	//adding new student
	milga_List,	//printing all the details of the students who deserve for scholarship
	most_Research,	//printing fname and lname of the student which work the most at his Research
	count_Milga_BA,	//printing the num of the students from BA degree which deserve fot the scholarship
	no_Reasearch_MA,	//printing the names of the MA students that don't do research
	overhead_Student,	//[rinting a fitting message if there is any student who study more than 15 courses
	remove_PHD_Failers,		//deleting all the PHD students which don't study at any course
};

void add(vector <Student*> &students);//adding a new student 
void milga(vector <Student*> & students);//printing only the student who deserve for the scholarship
Student * most_Reasearch_Hours(vector <Student*>& students);//checks which PHD student spend more hours at his research

int main()
{

	vector <Student*> students;// creating an empty vector "students", and its type is Student(pointer)
	int op;
	int count = 0;
	bool over15 = false;
	int count2 = 0;

	cout << "enter 0-7" << endl;
	cin >> op;
	while (op != stop)
	{

		switch (op)
		{
		case add_New_Student:
			add(students);//adding a new student
			break;

		case milga_List:
			milga(students);//printing the eligible students
			break;

		case most_Research:
		{
			Student* s = most_Reasearch_Hours(students);
			cout << "PHD student with most research hours: ";
			cout << s->get_Fname() << ' ' << s->get_Lname() << endl;
		}
		break;

		case count_Milga_BA:
			for_each(students.begin(), students.end(),
				[&count](Student * s)
				{if (s->studyType() == "BA" && s->milga()) count++; });//for each_loop combines a for loop with lambda
			cout << "#BA students for milga: " << count << endl;
			break;

		case no_Reasearch_MA:
			cout << "list of no research MA students : ";
			for_each(students.begin(), students.end(),
				[](Student * s) 
				{if (s->studyType() == "MA" && !((MA*)s)->Dosearch()) //if this is a MA student and also he doesn't do any research 
					cout << s->get_Fname() <<" "<< s->get_Lname() << endl; });
			//cout << endl;
			break;

		case overhead_Student:
			//if ()
			for_each(students.begin(), students.end(),
				[&over15](Student * s)
				{if (s->getCnum() > 15) 
						over15 = true; });//for each_loop combines a for loop with lambda
			if (over15)//if there is a student like this
				cout << "there is a student that takes more than 15 courses" << endl;
			else
				cout << "no student takes more than 15 courses" << endl;
			break;

		case remove_PHD_Failers:
			for_each(students.begin(), students.end(),
				[&students, &count2](Student * s)
				{if (s->studyType() == "PHD" && ((PHD*)s)->get_Cnum() == 0)
				students.erase(students.begin() + count2); ++count2; });//for each_loop combines a for loop with lambda

			for_each(students.begin(), students.end(), [](Student * s) {s->print(); });

			break;


		};
		cout << "enter 0-7" << endl;
		cin >> op;

	}

	system("pause");
	return 0;
}

void add(vector <Student*>& students)//adding new type of student
{
	int choice, id, Cnum, HR;//for the different cases
	string fname;
	string lname;
	int * grades;
	bool r;//for research
	cout << "enter 1 to add a BA student\n";
	cout << "enter 2 to add a MA student\n";
	cout << "enter 3 to add a PHD student\n";
	cin >> choice;
	cout << "enter id, first name, last name and number Of Courses\n";

	cin >> id >> fname >> lname >> Cnum;
	

	switch (choice)
	{
	case 1://BA student
		cout << "enter " << Cnum << " grades\n";
		grades = new int[Cnum];
		for (int i = 0; i < Cnum; i++)//entering grades
			cin >> grades[i];
		students.push_back(new BA(id, fname, lname, Cnum, grades));
		break;

	case 2://MA student
		cout << "enter " << Cnum << " grades\n";
		grades = new int[Cnum];
		for (int i = 0; i < Cnum; i++)//entering grades
			cin >> grades[i];
		cout << "enter 1 if the student does research and 0 if not\n";
		cin >> r;
		students.push_back(new MA(id, fname, lname, Cnum, grades, r));
		break;

	case 3://PHD student
		cout << "enter number of research hours\n";
		cin >> HR;
		students.push_back(new  PHD(id, fname, lname, Cnum, HR));
		break;

	default://at any other case
		cout << "Error" << endl;
		break;

	}

}

void milga(vector<Student*> & students)//printing only the student who deserve for the scholarship
{
	vector <Student*> ::iterator it;//creating an iterator which point at the vector's elements
	for (it = students.begin(); it != students.end(); it++)
	{
		if ((*it)->milga())//checks for the scholarship if the students deserve it
			(*it)->print();
	}
}

Student * most_Reasearch_Hours(vector<Student*>& students)//checks which PHD student spend more hours at his research
{
	int maxH = 0;//to initialize the max Hours
	bool isPHD = false;//assume from the start that there isn't any PHD student
	vector <Student*> ::iterator it;//creating an iterator which point at the vector's elements

	for (it = students.begin(); it != students.end(); it++)
	{
		if ((*it)->studyType() == "PHD")//if the student is a PHD student
		{
			isPHD = true;//there is a PHD student 
			if ((*it)->getNweek() > maxH)//for each time it will be updated till the student with the more Hours
				maxH = (*it)->getNweek();//update
		}
	}
	if (!isPHD)//if there weren't any PHD student at all
		return NULL;
	
	for (it = students.begin(); it != students.end(); it++)//going through over again
		if (maxH = (*it)->getNweek())
			return (*it);//returning the substance of "it" - the PHD STUDENT
	
	return NULL;//?
}

/*
output:
enter 0-7
1
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
1
enter id, first name, last name and number Of Courses
12 rinat canaan 3
enter 3 grades
100 99 90
enter 0-7
1
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
2
enter id, first name, last name and number Of Courses
13 Avi cohen 16
enter 16 grades
90 56 78 5 78 8 9 67 89 56 45 34 89 78 56
12
enter 1 if the student does research and 0 if not
1
enter 0-7
1
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
3
enter id, first name, last name and number Of Courses
15 hodaya levi 7
enter number of research hours
30
enter 0-7
2
enter 0-7
1
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
1
enter id, first name, last name and number Of Courses
16 eli ohana 11
enter 11 grades
100 100 100 100 100 100 100 100 100 90 90
enter 0-7
1
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
2
enter id, first name, last name and number Of Courses
45 nanci gabay 7
enter 7 grades
100 90 100 90 100 90 100
enter 1 if the student does research and 0 if not
1
enter 0-7
1
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
3
enter id, first name, last name and number Of Courses
56
noa geri 3
enter number of research hours
45
enter 0-7
2
ID: 16
first name: eli
last name: ohana
num courses: 11
grades: 100 100 100 100 100 100 100 100 100 90 90
ID: 45
first name: nanci
last name: gabay
num courses: 7
grades: 100 90 100 90 100 90 100
research: yes
enter 0-7
3
PHD student with most research hours: hodaya levi
enter 0-7
4
#BA students for milga: 1
enter 0-7
5
list of no research MA students : enter 0-7
6
there is a student that takes more than 15 courses
enter 0-7
7
ID: 12
first name: rinat
last name: canaan
num courses: 3
grades: 100 99 90
ID: 13
first name: Avi
last name: cohen
num courses: 16
grades: 90 56 78 5 78 8 9 67 89 56 45 34 89 78 56 12
research: yes
ID: 15
first name: hodaya
last name: levi
num courses: 7
hours: 30
ID: 16
first name: eli
last name: ohana
num courses: 11
grades: 100 100 100 100 100 100 100 100 100 90 90
ID: 45
first name: nanci
last name: gabay
num courses: 7
grades: 100 90 100 90 100 90 100
research: yes
ID: 56
first name: noa
last name: geri
num courses: 3
hours: 45
enter 0-7
1
enter 1 to add a BA student
enter 2 to add a MA student
enter 3 to add a PHD student
2
enter id, first name, last name and number Of Courses
23 dev bell 3
enter 3 grades
12 23 45
enter 1 if the student does research and 0 if not
0
enter 0-7
5
list of no research MA students : dev bell
enter 0-7
0
Press any key to continue . . .

*/