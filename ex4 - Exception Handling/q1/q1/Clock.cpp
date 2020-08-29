#include "Clock.h"
#include "Account.h"
#include <iostream>
#include <string>
using namespace std;

Clock::Clock()//default constructor
{
	hour = 0;
	minute = 0;
	second = 0;
}

Clock::Clock(int myHour, int myMinute, int mySecond)//constructor
{
	bool sec = true;//if second is at the proper range 
	bool min = true;//if minute is at the proper range 
	bool h = true;//if hour is at the proper range 

	if ((myHour >= 24) || (myHour < 0))
		h = false;
	if ((myMinute >= 60) || (myMinute < 0))
		min = false;
	if ((mySecond >= 60) || (mySecond < 0))
		sec = false;

	while (!h||!min||!sec)//as long as one of the time ingredient is wrong
	{
		hour = 0;//calibrating hour
		minute = 0;//calibrating minute
		second = 0;//calibrating second

		try //in case the values will be wrong (won't be at the proper range)
		{

			if ((mySecond >= 60) && (sec == false)) //if seconds format is 59+
			{
				sec = true;
				string s = "Invalid time - more than 60 seconds. \n";
				throw s;
			}
			if ((myMinute >= 60) && (min == false))//if minutes format is 59+
			{
				min= true;
				string s = "Invalid time - more than 60 minutes. \n";
				throw s;
			}
			if ((myHour >= 24)&&(h == false))//if hours format is 23+
			{
				h = true;
				string s = "Invalid time - more than 24 hours. \n";
				throw s;
			}

			if ((mySecond < 0) && (sec == false))//if seconds format is negative
			{
				sec = true;
				string s = "Invalid time - negative number of seconds. \n";
				throw s;
			}
			if ((myMinute < 0) && (min == false))//if minutes format is negative
			{
				min = true;
				string s = "Invalid time - negative number of minutes. \n";
				throw s;
			}
			if ((myHour < 0) && (h == false))//if hours format is negative
			{
				h = true;
				string s = "Invalid time - negative number of hours. \n";
				throw s;
			}
		}
		catch (string s)
		{
			cout << s;
		}	
	}
	if ((myHour >= 0) && (myHour < 24))//in case this is the right time
	{
		if ((myMinute >= 0) && (myMinute < 60))
			if ((mySecond >= 0) && (mySecond < 60))
			{
				hour = myHour;
				minute = myMinute;
				second = mySecond;
			}
	}
}

Clock::Clock(const Clock & time)//copy constructor
{
	hour = time.hour;
	minute = time.minute;
	second = time.second;
}

Clock::~Clock()//destructor
{
}

void Clock::setHr(int myHour)//setting hour
{
		hour = myHour;
}

void Clock::setMin(int myMinute)//setting minute
{
	minute = myMinute;
}

void Clock::setSec(int mySecond)//setting second
{
	second = mySecond;
}

int Clock::getHr()
{
	return hour;
}

int Clock::getMin()
{
	return minute;
}

int Clock::getSec()
{
	return second;
}

Clock Clock::operator+=(int mySecond)//adding seconds
{
	int newSec = second + mySecond;
	if ((newSec >= 0) && (newSec < 60))//the usual case
	{
		second = newSec;
	}
	else//if it is out of range
	{
		second = newSec - 60;//nulling the seconds as it should be
		minute++;//going to the next minute
		if (minute >= 60)
		{
			minute = 0;
			hour++;//going to the next hour
			if (hour > 23)
				hour = 0;
		}
	}
	Clock temp(hour, minute, second);
	return temp;
}

ostream & operator<<(ostream & os, const Clock & time)//printing time
{
	if (time.hour < 10)//in case hour represented in a single digit
		os << '0' << time.hour<< ":";
	else
		os << time.hour<<":";

	if (time.minute < 10)//in case minute represented in a single digit
		os << '0' << time.minute<< ":";
	else
		os << time.minute<< ":";

	if (time.second < 10)//in case second represented in a single digit
		os << '0' << time.second;
	else
		os << time.second;

	return os;
}

istream & operator>>(istream & is, Clock & time)//reading the time
{
	char colon;//":"
	is >> time.hour >> colon >> time.minute >> colon >> time.second;
	return is;
}
