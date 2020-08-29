#pragma once
class Date
{
private:
	int day;
	int month;
	int year;

public:
	
	//Date(); //a default constructor
	Date (int myDay = 1, int myMonth = 1 , int myYear= 1970);//constructor
	Date(Date &d);//copy contructor 
	
	void setDate(int, int, int);

	/*int getDay();
	int getMonth();
	int getYear();*/

	Date operator++(); //++day
	Date operator++(int); //day++
	Date operator+= (int);//(date1+=date2)	,chanching the date acrodding to the dayNumbers that will show at the right side of the fraction 

	bool operator>(Date &rhs);  // inquality check
	bool operator<(Date &rhs); // inquality check
	bool operator==(Date &rhs); // equality check

	void print();  // output
};