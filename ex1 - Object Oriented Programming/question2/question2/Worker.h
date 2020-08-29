#pragma once
#include <iostream>
#include <cstring>
using namespace std;
class Worker
{
private:
	int id;
	char name[21];
	float salary;
	int numWorked;
	int exHours;
public:
	void setId(int idn);//id number
	int getId();
	void setName(char  myName[21]);//setting name
	char * getName();
	void setSalary(float slr);//setting money per hour
	float getSalary();
	void set_numWorked(int count);//how many hours the worker worked
	int get_numWorked();
	void set_exHours(int x);//how many hours the worker worker extra hours
	int get_exHours();
	float calSlr();//calculating salary
	int d;
};