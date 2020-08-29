#include "q2\QueueStack.h"
//name:hodaya rachel bismut i.d:322269333
#include "QueueStack.h"
QueueStack::QueueStack()//constructor
{

}


QueueStack::~QueueStack()//distructor
{
	
}

void QueueStack::clear()//Since the queue is realized by a stack then I simply empty the cartridge
{
	this->clear();
}

int QueueStack::dequeue()//Takes the first organ in queue and returns it
{
	stack<int> temp;//Stack cartridge
	while (!data.empty())//Moves all organs from the first cartridge to the second
	{
		temp.push(data.top());
		data.pop();
	}
	//Saves the first organ on the second cartridge and takes it out of the cartridge
	int x;
	x = temp.top();
	temp.pop();
	while (!temp.empty())//Returns all values to the original cartridge
	{
		data.push(temp.top());
		temp.pop();
	}
	return x;//return the value
}

void QueueStack::enqueue(int value)//Putting an organ in queue
{
	data.push(value);//pushing the value into the stack
}

int QueueStack::front()//Returns the value of the first element
{
	stack<int> temp;//Stack cartridge
	while (!data.empty())//Moves all organs from the first cartridge to the second
	{
		temp.push(data.top());
		data.pop();
	}
	//Saves the first organ on the second cartridge
	int x;
	x = temp.top();
	while (!temp.empty())//Returns all values to the original cartridge
	{
		data.push(temp.top());
		temp.pop();
	}
	return x;//return the value
}
//Since the line is realized by a cartridge I check if the cartridge is empty
//so it means that the queue is also empty
bool QueueStack::isEmpty() const
{
	return data.empty();
}



