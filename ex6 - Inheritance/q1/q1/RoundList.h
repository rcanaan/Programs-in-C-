#pragma once
#include <iostream>
#include "List.h"
using namespace std;

class RoundList : public List//RoundList inherits from List
{
public:
	RoundList();//constructor
	~RoundList();//destructor


	void addToEnd(int val);//adding a new number to the end of the list
	int search(int index);// returning the value where the index is
	int longList();//counts the amount of nodes at the List 
};