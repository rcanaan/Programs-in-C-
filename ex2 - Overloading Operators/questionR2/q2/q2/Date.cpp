#include <iostream>
using namespace std;
#include "Date.h"
//
//Date::Date()//default constructor
//{
//
//}
Date::Date(int myDay, int myMonth, int myYear)//default constructor
{
	if (myDay < 1 || myDay > 30)//if the day isn't at the correct range
	{
		cout << "Error day" << endl;
		day = 1;//first day at the month
	}
	else
		day = myDay;//an ordinary situation

	if (myMonth < 1 || myMonth > 12)//if the month isn't at the correct range
	{
		cout << "Error month" << endl;
		month = 1;//heading of the year
	}
	else
		month = myMonth;

	if (myYear < 1970 || myYear > 2099)//if the year isn't at the correct range
	{
		cout << "Error year" << endl;
		year = 1970;
	}
	else
		year = myYear;
}
Date::Date(Date &d) //copy constructor
{
	day = d.day;
	month = d.month;
	year = d.year;
}
void Date::setDate(int d, int m, int y)//setting date
{
	day = d;
	month = m;
	year = y;
}
Date Date :: operator ++ () //++day, first promoting and then printing
{
	++day;
	if (day > 30)//if the day isn't at the correct range
	{
		day = 1;
		month++;//new month
		if (month > 12)//if this is a new year
		{
			month = 1;//new year
			year++;
		}
	}

	Date temp(day, month, year);//definding date
	return temp;
}
Date Date ::operator ++ (int n)//first printing and afterwards promoting it
{
	Date temp(day, month, year);
	day++;
	if (day > 30)//if the day isn't at the correct range
	{
		day = 1;//heading of month
		month++;//new month
		if (month > 12)//in case this is a new year
		{
			month = 1;
			year++;//promoting the year
		}
	}
	return temp;
}
Date Date:: operator += (int a)//chanching the date acrodding to the dayNumbers that will show at the right side of the fraction (date1+=date2)
{
	int newDay = day + a;
	if (newDay < 31)//usual case
	{
		day = newDay;
	}
	else//if the newDay will be bigger than 30, the usual numbers at month
	{
		day = newDay - 30;//nulling the day
		month++;
		if (month > 12)
		{
			month = 1;
			year++;
		}	
	}
	Date temp(day, month, year);
	return temp;
}
bool Date ::operator > (Date &rhs) // inquality check
{
	if (year > rhs.year)//if the year is bigger
		return true;
	else if (year == rhs.year)//if this is the same year
	{
		if (month > rhs.month)//is the month is bigger
			return true;
		else if (month < rhs.month)//if the month is smaller
			return false;
		/*if (month == rhs.month)*///if this is the same month
		else
		{
			if (day > rhs.day)//if the day is bigger
				return true;
			else
				return false;
		}	
	}
	else	//if the year is smaller
		return false;
}
bool Date ::operator < (Date &rhs) // inquality check
{
	if (!(*this > rhs))//if the date 1 is not bigger than date 2, return true (meaning - smaller)
		return true;
	return false;
	
}
bool Date:: operator == (Date &rhs) // equality check
{
	if (year == rhs.year)  // in case the years are the same
		if (month == rhs.month)// in case the months are the same
			if (day == rhs.day) // in case the days are the same
				return true;
	return false;
}
void Date:: print()
{
	cout << day << "/" << month << "/" << year << endl; // prining dates
}