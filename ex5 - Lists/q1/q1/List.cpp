#include "List.h"
#include <iostream>
using namespace std;

List::List()//default constructor
{
	head = NULL;// nullptr;
}

List::List(const List & ls)//copy constructor
{
	Link * src;//pointer to the source 
	Link *trg;//pointer to the target
	head = NULL;

	head = new Link(ls.head->key, NULL);//nullptr);

	src = ls.head;
	trg = head;

	while (src->next != nullptr)
	{
		trg->next = new Link((src->next)->key, NULL);// nullptr);
		src = src->next;
		trg = trg->next;

	}
}

List::~List()//destructor
{
	clear();
}

List & List::operator=(const List & rhs)
{
	if (!isEmpty())
		clear();

	Link * src;//pointer to the source 
	Link *trg;//pointer to the target
	head = NULL;

	head = new Link(rhs.head->key, NULL);//nullptr);

	src = rhs.head;
	trg = head;

	while (src->next != NULL)//nullptr)
	{
		trg->next = new Link((src->next)->key, NULL);//nullptr);
		src = src->next;
		trg = trg->next;

	}

	return *this;
		
}

void List::add(int val)//insert first
{
	Link * temp = new Link(val, head);
	head = temp;

	if (head == NULL)
		throw "failed allocating memory";

}

void List::insert(int k)//inserting new link to the sorted list
{
	Link * p = head;
//	Link * q = p->next;

	if (k < p->key)//if k is the smallest number
	{
		/*Link  * temp = new Link(k, head);
		head = temp;
		return;*/
		head = new Link(k, head);
		return;

	}

	//while (p->next != NULL)//((p != NULL) && (q != NULL))
	//{
	//	if ((k > p->key) && (k < q->key))//in case k between p and q values
	//	{
	//		Link * temp = new Link(k, q);
	//		p->next = temp;
	//		return;
	//	}

	//	p = q; //p++
	//	q = q->next;//q++
	//}
	//if (k > q->key)//if k is the biggest number
	//{
	//	q = new Link(k, q);//q will point at the new number
	//	return;
	while (p->next != NULL) // ad long as we didn't reach last node
	{
		if (p->key < k && k < (p->next)->key) // if we found two values the key needs to be between
		{
			p->next = new Link(k, p->next); // insert the key between them
			return; // and finish
		}
		p = p->next; // in order to move on to next node
	}
	while (p->next != NULL)// if key is'nt inserted between to nodes- then it must be a bigger number than all of the list's numbers 
	{
		p = p->next; // moving on to last node
	}
	if (k > p->key) //in case  key is a bigger number than all of the list's numbers 
	{
		p->next = new Link(k, p->next); // inserting it to last place of the list
		return;
	
	}

	
}

int List::firstElement() // checking for the first element at each List
{
	if (isEmpty())
		throw "list is empty";
	return (head->key);
}

List::Link * List::search(const int & value)//searching for specific link
{
	Link * p = head;
	while (p != NULL)//nullptr)
	{
		if (value == (p->key))
			return p;
		p = p->next;//promoting
	}
	return p;//if the list is empty
}

void List::clear()
{
	//Link* next;
	//	for (Link *p = head; p != NULL; p = next)
	//	{
	//		// delete the element pointed to by p
	//		next = p->next;
	//		p->next = NULL;
	//		delete p;
	//	}
	//// mark that the List contains no elements
	//head = NULL;


	Link * p = head;
	Link * q = p->next;//q is after p
	for (p = head; p != NULL; p = q) //promoting p to point where q points to
	{
		q = p->next;//
		p->next = NULL;//nullptr;// separating between the first link to its next
		delete p;//deleting the specific link
	}

}

bool List::isEmpty()// const//checing if the List is empty from links and data
{
	return head = NULL;//nullptr;
}

void List::removeFirst()//deleting the first link
{

	if (isEmpty())
		throw "the List is empty, no Elemnt to remove";
	//Link * p = head;
	//head = p->next;
	//p->next = NULL;
	//delete p;


	/*Link * p = head->next;
	head->next = NULL;
	delete head;
	head = p;*/
}

void List::remove(int k)//removing specific link
{
	bool flag = false;
	if (head==NULL ||!search(k))//if the list is empty, or the returned pointer points to NULL
		throw "value not found";
	Link * p = head;
	if (k == head->key)//in case the wanted link is the first one
		{
			head = head->next; // skipping the node by adding the next node's address in head
			flag = true; // there's no exception needed
			return;
		}
	//	removeFirst();
	else
	{
		while ((p->next != NULL) && (flag == false)&&((p->next)->key != k))//as long the next link is different in its value and doesnt point to NULL
			p = p->next;//promoting p to the next link, p++
		p->next = p->next->next;//when this is the wanted value, skip on it (instead of earasing it)
	}
}

List::Link::Link(int linkVal, Link * nxt)// combined default constructor and usual constructor
{
	key = linkVal;
	next = nxt;
}

List::Link::Link(const Link & lk)//copy constructor
{
	key = lk.key;
	next = lk.next;
}

istream & operator>>(istream & is,  List & l)//reading the links
{
	int key1, key2;//used are temps
	is >> key1;//reading the forst key
	l.setList(key1);//creating a new link
	is >> key2;

	while (key2 > key1)//as long the list sti goes from small to bigger
	{
		l.setList(key2);
		key1 = key2;//ready to read the next value
		is >> key2;
	}
	return is;
}

void List::print() const
{
	for (Link*p = head; p != NULL; p = p->next) // a loop in order to go over all nodes
		cout << p->key << " "; // print current node
}

void List::setList(int k)
{
	//if (!isEmpty())
	if (head == NULL)
	{
		head = new Link(k, head);
	}
	
	else// if the list isn't empty
	{
		Link * p = head;
		while (p->next != NULL)
			p = p->next;//p++, to the next link
		p->next = new Link(k, p->next);//creating a new value and putting it at the end ot the list 
	}
}

ostream & operator<<(ostream & os, const List & l)//printing the links from small to the bigger
{
	
	l.print();//using the print function to print the list 
	return os;
}