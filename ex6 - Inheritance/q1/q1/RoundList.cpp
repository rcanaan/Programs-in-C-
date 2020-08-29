#include "RoundList.h"
#include "List.h"
//both of thr c-tor and the d-tor are empty because it is still 
//has only one pointer- head
RoundList::RoundList(): List()
{

}

RoundList::~RoundList() //: List()
{

}

void RoundList::addToEnd(int val)//adding a new number to the end of the list
{
	if (head == NULL)//if the List is empty
		this-> add(val);
	else
	{
		Link * p = head;
		while ((p->next) != NULL)//as long this is not the end of the list' continue
			p = p->next;
		p->next = new Link(val, p->next);//when its the last node, add there the new val
	}
}

int RoundList::search(int index)// returning the value where the index is
{
	if (head == NULL)//in case the list is empty
		return -1;
	if (index >= 0)//if the index is at the proper range
	{
		int numNodes = longList();
		int _index = index % numNodes;//the real location, in case the index will be bigger than the numNodes
		int count = 0;
		int num;//the wanted number

		if (index >= numNodes)
		{
			for (Link * p = head; p != NULL; p = p->next)
			{
				if (count == _index)
					num = p->key;
				count++;
			}
				
			return num;
		}

		else//in case the index is smaller than the numNodes
		{
			for (Link * p = head; p != NULL; p = p->next)
			{
				if (count == index)
				{
					num = p->key;
					return num;
				}
				count++;
			}
		}
	}
}

int RoundList::longList()//counts the amount of nodes at the List 
{
	int count = 1;//assuming that the first node is already inside
	Link * p = head;

	if (head == NULL)//in case the list is empty
		return 0;

	while (p->next != NULL)
	{
		count++;//counting how many nodes
		p = p->next;//p++
	}
	return count;
}
