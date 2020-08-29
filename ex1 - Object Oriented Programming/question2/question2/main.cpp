#include "Worker.h"
#include <cstring>
using namespace std;
/*
Main Program

Name - Rinat Canaan ID 207744012
course - "workshop at C++"
exercise 1 question 2
description:
this program receives details about workers (salart, id, name, hours work and extra hours) 
and calculates which worker has the highest salary and wich worker worked  more hours compare to others.

*/
int main()
{
	int id, numw, exNumw;
	float slr;
	char name[20];
	Worker p1, p2, p3;// i was uncertain what should i do - defining a few types of class or making an dinamic array, so i initialized the values inside p2
					// p1 - new worker, p2 -the worker with the highest salary, p3- the worker who worked the most
	char pName[] = "a";
	p2.setId(00000);	p2.setName(pName);	
	p2.setSalary(0);	p2.set_numWorked(0);	p2.set_exHours(0); 
	//initializing the values inside p2 (the worker with the highest salary)

	
	cout << "enter details, to end enter 0" << endl;
	cin >> id;
	while (id != 0)//to finish the program the user will put 0
	{
		cin >> name >> slr >> numw	>> exNumw;
		if ((slr < 0) || (numw < 0) || (exNumw < 0))//if the values doesn't make any sense
			cout << "ERROR" << endl;
		else
		{//setting the values into the first worker
			p1.setId(id);
			p1.setName(name);	
			p1.setSalary(slr);
			p1.set_numWorked(numw);	
			p1.set_exHours(exNumw);

			//float p1Salary = p1.calSlr(), p2Salary = p2.calSlr();
			//int p1_TotalHrs = p1.get_numWorked() + p1.get_exHours();
		//	int p3_TotalHrs = p3.get_numWorked() + p3.get_exHours();
			if (p1.calSlr() >= p2.calSlr())//in case p1 is bigger than p2 at the salary
				p2 = p1;
			if ((p1.get_numWorked() + p1.get_exHours()) >= (p3.get_numWorked() + p3.get_exHours()))//in case p1  is hard working than p3
				p3 = p1;
		}
		cin >> id;
	}

	cout << "highest salary: " << p2.getId() << " " << p2.getName() << endl;;
	cout << "hardest worker: " << p3.getId() << " " << p3.getName() << endl;;
		
	


	system("pause");
	return 0;
}
/*
enter details, to end enter 0
12 ab 50 40 2
13 bc 100 30 0
14 cd 30 45 10
0
highest salary: 13 bc
hardest worker: 14 cd

enter details, to end enter 0
123456789   avraham     50  40  2
135792468   yaakov      100 30  0
975312468   sara    30  45  10
0
highest salary: 135792468 yaakov
hardest worker: 975312468 sara

enter details, to end enter 0
1 aaa 100 40 5
2 bbb 100 45 0
3 ccc 100 47 2
0
highest salary: 3        ccc
hardest worker: 3        ccc
*/