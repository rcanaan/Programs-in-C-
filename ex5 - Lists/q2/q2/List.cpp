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

	while (src->next != NULL)
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
	try
	{
		Link * temp = new Link(val, head);
		head = temp;
		//head = new Link(_value, head);//another option
		if (head == NULL)
			throw "failed allocating memory";
	}
	catch (const char * str)
	{
		cout << str << endl;
	}
}


bool List::isEmpty() const
{
	return head == NULL; // if the list is empty- func will return true- else-false
}

int List::firstElement() const
{
	try
	{
		if (isEmpty())  // if the list is empty, then throw an exception
		{
			throw "the List is empty, no first Element";
		}
		return head->key; // if not, retun the value of the first element
	}
	catch (const char*str)
	{
		cout << str << endl;
	}

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
	Link* src; // source will point to the next node we need to delete
	for (Link * p = head; p != NULL; p = src)  // as long as we didn't reach the end of the list
	{
		src = p->next; // source will point to the next node
		p->next = NULL; // inserting null in the current node 
		delete p; // deleting the current node
	}
	// mark that the List contains no elements,
	head = NULL;
}



void List::removeFirst()
{
	try
	{
		// make sure there is a first element
		if (isEmpty())
			throw "the List is empty, no Elements to remove";
		//	 save pointer to the removed node
		Link *p = head;
		// reassign the first node 
		head = p->next;
		p->next = NULL;
		// recover memory used by the first element 
		delete p;

	}
	catch (const char*str)
	{
		cout << str << endl;
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

istream & operator>>(istream & is, List & l)//reading the links
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
List merge(List & lst1, List & lst2)//gets two devided lists, and returning a new merged List
{
	List new_lst, temp;
	int n;

	if (lst1.isEmpty())//if lst1 is empty
		return lst2;
	if (lst2.isEmpty())//if lst2 is empty
		return lst1;

	while (!lst1.isEmpty() && !lst2.isEmpty())/// as long as we didn't reach the end of both lists
	{
		if (lst1.firstElement() < lst2.firstElement())
		{
			n = lst1.firstElement();
			//new_lst.add(n);//updating the new list
			lst1.removeFirst();//earasing the specific link
		}
		else
		{
			n = lst2.firstElement();
			//new_lst.add(n);//updating the new list
			lst2.removeFirst();//earasing the specific link
		}
		new_lst.add(n);//updating the new list
	}

	while (!lst1.isEmpty()) // if we finished list b, all there's left is to add the sorted numbers of list a into list c
	{
		n = lst1.firstElement(); //taking first node
		new_lst.add(n); // adding into c
		lst1.removeFirst(); // removing in order to move on to next node
	}
	while (!lst2.isEmpty())// if we finished list a, all there's left is to add the sorted numbers of list b into list c
	{
		n = lst2.firstElement();//taking first node
		new_lst.add(n);    // adding into c
		lst2.removeFirst(); // removing in order to move on to next node
	}


	while (!new_lst.isEmpty())
	{
		n = new_lst.firstElement();//coping the forst link form "new_lst" (that shoult be the last)
		temp.add(n);//putting it into the new list - that will be organize 
		new_lst.removeFirst();
	}

	return temp;
}

List makeSet(List a)//turning the list into a group (deleliting repeated numbers)
{
	List b;//to copy the wanted numbers
	List c;//for converting the list (because it is reversed)
	int n;

	n = a.firstElement();
	b.add(n);//coping the first elemet
	a.removeFirst();//earesing it from "a" list

	while (!a.isEmpty())//taking the unmultiplied numbers to a new list -"b"
	{
		n = a.firstElement();
		if (b.firstElement() == n)//if the numbers are the same 
			a.removeFirst();//earesing it from "a" list
		else
		{
			b.add(n);//adding the number to the "b" list 
			a.removeFirst();//earesing it from "a" list
		}

	}

	while (!b.isEmpty())//reversing the list 
	{
		n = b.firstElement();
		c.add(n);
		b.removeFirst();
	}

	return c;
}
