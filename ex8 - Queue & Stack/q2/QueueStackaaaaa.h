//name:hodaya rachel bismut i.d:322269333
#pragma once
#include<stack>
#include<iostream>
#include<cstdlib>
using namespace std;
class Queue//A class of Queue without realizing a pure class
{
public:
	virtual void clear() = 0;
	virtual void enqueue(int value) = 0;
	virtual int dequeue() = 0;
	virtual int front() = 0;
	virtual bool isEmpty() const = 0;
};

//A class of queue by using a stack
class QueueStack : public Queue
{
protected:
	stack<int> data;        
public:
	QueueStack();//constructor
	~QueueStack();//distructor
	void clear() override;//clear the queue
	int dequeue() override;//Takes the first organ in queue and returns it
	void enqueue(int value) override;//Putting an organ in queue
	int front() override;//Returns the value of the first element
	bool isEmpty() const override;//Checks if the queue is empty
};




