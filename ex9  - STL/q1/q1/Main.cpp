/*
Rinat Canaan ID 207744012
Course - "workshop at c++"
ex 9
this program uses the students classes from exrecise 7, with using the STL library and
*/
#include <iostream>
using namespace std;
#include "Student.h"
#include <algorithm>
#include "MA.h"
#include "BA.h"
#include "PHD.h"
#include <string>
#include <vector>//this liberary helps us define easily a data stucture - such as vector

void add(vector <Student*>& s);//adding a new student
void milga(vector<Student*> s); //global function which prints only the students who deserve for scholarship
//Student* most_Research_Hours(vector<Student*> s);//checks which PHD student worked invest the most hours spending at research
enum option
{
	stop,	//	סיום התוכנית
	addNewStudent,	//	הוספת סטודנט חדש
	milgaList,	//	הדפסת פרטי כל התלמידים הזכאים למלגה
	mostResearch,	//	הדפסת שם (משפחה ופרטי) של הסטודנט שעוסק הכי הרבה שעות במחקר
	countMilgaBA,	//	הדפסת מספר הסטודנטים לתואר ראשון הזכאים למלגה
	noResearchMA,	//	הדפסת שמות (משפחה ופרטי) של הסטודנטים MA שאינם עוסקים במחקר
	overheadStudent,	//	הדפסת הודעה מתאימה, האם קיים סטודנט שלומד יותר מ- 15 קורסים
	removePHDFailers,	//	מחיקת כל הסטודנטים לתואר שלישי שאינם לומדים באף קורס
};

int main()
{

	int op;//option
	cout << "enter 0-7\n";
	cin >> op;
	while (op != stop)
	{
		switch (op)
		{

		case addNewStudent:
			add();
			break;

		case milgaList:
			milga();
			break;

		case mostResearch:
		{
			Student* s = mostResearchHours();
			cout << "PHD studnet with most research hours: ";
			cout << s->getFname() << ' ' << s->getFname() << endl;
		}


		}
	}



	system("pause");
	return 0;
}

void add(vector <Student*>& s) //adding a new student
{
	int* grades;
	bool r;//research
	int id, numc, choice, numh;//id and num courses temps, choice for the cases, numh for num hours for project
	char* fname = new char[25];//first name temp
	char* lname = new char[25];//last name temp
	Student* temp;//a student array temp

	cout << "enter 1 to add a BA student\n";
	cout << "enter 2 to add a MA student\n";
	cout << "enter 3 to add a PHD student\n";
	cin >> choice;
	cout << "enter id, first name, last name and number Of Courses\n";
	cin >> id >> fname >> lname >> numc;

	switch (choice)//for deciding which type of student
	{
	case 1://for BA student
		cout << "enter " << numc << " grades\n";
		grades = new int[numc];
		for (int i = 0; i < numc; i++)
			cin >> grades[i];
		temp = new BA(id, fname, lname, numc, grades);//creating new student from BA type
		break;

	case 2://for MA student
		cout << "enter " << numc << " grades\n";
		grades = new int[numc];
		for (int i = 0; i < numc; i++)
			cin >> grades[i];
		cout << "enter 1 if the student does research and 0 if not\n";
		cin >> r;//true or false
		temp = new MA(id, fname, lname, numc, grades, r);//creating new student from MA type
		break;

	case 3:
		cout << "enter number of research hours\n";
		cin >> numh;
		temp = new PHD(id, fname, lname, numc, numh);//creating new student from PHD type
		break;

	default:
		cout << "ERROR" << endl;
		break;
	}
	s.push_back(temp);//inserting the new student into the vector

}
void milga(vector<Student*> s)//global function which prints only the students who deserve for scholarship
{
	vector<Student*> ::iterator it;//creating an iterator to the vector
	it = s.begin();//allocating the iterator 
	for (; it != s.end(); it++)
		if ((*it)->milga())
			(*it)->print();
}

//Student* most_Research_Hours(vector<Student*> s)//checks which PHD student worked invest the most hours spending at research
//{
//	vector<Student*> ::iterator it;//will help to go over the vector
//	Student* ptr ;//pointer that will be returned at last
//	for (it = s.begin(); it != s.end(); it++)
//	{
//		if ((*it)/*->studyType()*/=="PHD")
//			if ((*it)()
//	}
//	return ptr;
//
///}