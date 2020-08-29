#pragma once
#include <iostream>
using namespace std;

class Clock//defining the class "clock"
{
private:
	int hour;//between 0-23
	int minute;//between 0-59
	int second;//between 0-59

public:
	Clock();//default constructor
	Clock(int myHour, int myMinute, int mySecond);//constructor
	Clock(const Clock & time);//copy constructor
	~Clock();//destructor

	void setHr(int myHour);//setting hour
	void setMin(int myMinute);//setting minute
	void setSec(int mySecond);//setting second

	int getHr();
	int getMin();
	int getSec();

	Clock operator += (int mySecond);//adding seconds

	friend ostream & operator << (ostream &os, const Clock & time);//printing the time (at "cin" format)
	friend istream & operator >> (istream &is, Clock & time);//reading the time (at "cout" format)
};