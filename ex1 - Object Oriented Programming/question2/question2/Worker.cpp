#include "Worker.h"
#include <iostream>
#include <cstring>

void Worker::setId(int idn)//setting id value
{
	id = idn;
}
int Worker::getId()
{
	return id;
}
void  Worker::setName(char myName[21])//copying names
{
	strcpy_s(name,20, myName);
//strcpy(name, myName);
}
char * Worker::getName()
{
	return name;
}
void Worker::setSalary(float slr)//setting money per hour
{
	salary = slr;
}
float Worker::getSalary()
{
	return salary;
}
void Worker::set_numWorked(int count)//how many hours the worker worked
{
	numWorked = count;
}
int Worker::get_numWorked()
{
	return numWorked;
}
void Worker::set_exHours(int x)//how many hours the worker worker extra hours
{
	exHours = x;
}
int Worker::get_exHours()
{
	return exHours;
}
float Worker::calSlr()//calculating salary
{
	float sum;
	sum = (float(numWorked * salary) + float(exHours * 1.5 * salary));
	return sum;
}