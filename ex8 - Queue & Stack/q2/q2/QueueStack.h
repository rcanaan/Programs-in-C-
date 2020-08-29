#pragma once
//template <class T>
#include <stack>
#include "Queue.h"
#include<cstdlib>
using namespace std;

class QueueStack : public Queue
{
protected:
	stack < int > a;//for inserting
	stack < int > b;//for deleting


public:
	QueueStack();//constructor
	~QueueStack();//destructor
	void clear() override;//deletes 
	int dequeue() override;//deleting values
	void enqueue(int value) override;//inserting values
	int front() override;//sees what the first note is
	bool isEmpty() const override;//checks if empty
	//int size() override;

};


