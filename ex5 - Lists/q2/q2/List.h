#pragma once
#include <iostream>
using namespace std;
class List//for the whole structure
{
protected:
	class Link//for every node
	{
	public:

		Link(int linkVal = 0, Link * nxt = NULL);// combined default constructor and usual constructor
		Link(const Link & lk);//copy constructor

		int key;//the val of every link (known also as "node")
		Link * next;//will point to the next node/link
	};//end of Link class

protected:
	Link * head;//will point to the beginning of the links

public:

	List();//default constructor
	List(const List &);//copy constructor
	~List();//destructor, will call to the clear function

	//void operator= (const List &);//operator "hasama"
	List & operator= (const List &);//operator "hasama"

	//methods 
	void add(int val);//adding to the beginning of the list

	int firstElement() const;//checking for the first element at each List
	Link * search(const int  & value);//searching for specific link

	void clear();//deleting all the list, will used by the destructor
	bool isEmpty() const;//const;//checking if the List is empty from links and data
	void removeFirst(); // removing first element

	void print() const;//printing, help fuction for "<<"
	void setList(int k);//set every new link, help function to ">>"



	friend ostream & operator << (ostream &os, const List &);
	friend istream & operator >> (istream &is, List &);





};