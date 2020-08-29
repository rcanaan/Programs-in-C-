
#include <stack>
#include "Queue.h"
#include "QueueStack.h"

QueueStack::QueueStack()
{
}

QueueStack::~QueueStack()
{
}

void QueueStack::clear()//deletes

{
	this->clear();//using the clear function of stack
}
int QueueStack::dequeue()	//deleting values
{
	
	int v;
	int x ;
	if (!b.empty())
		x = b.top();
	if (b.size() == 0)//if the stack for deleting is empty, it means that we finish
	{
		bool f;
		while (!a.empty())
		{
		
			v = a.top();//v represets the first value at the inserting stack
			 a.pop();
			 b.push(v);
			 x = b.top();

		}
	
	}
	if (!b.empty())
			b.pop();

	return (x);//returns the value;
}
void QueueStack ::enqueue(int value) //inserting values
{
	a.push(value);//inserting
		
}

int QueueStack::front() //sees what the first note is
{
	int v;
	if (b.size() == 0)
	{
		while (a.size() > 0)
		{
			b.push(a.top());
			a.pop();
		}
	}
	return (b.top());
}
bool QueueStack:: isEmpty() const //checks if empty
{
	return (a.empty() && b.empty());
}
