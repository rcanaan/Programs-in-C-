#ifndef SEARCH_TREE_H
#define SEARCH_TREE_H

#include "Tree.h"
#include <iostream>
using namespace std;


template<class T>
class SearchTree: public Tree<T>
{

public:
	// protocol for search trees
	void add(T value);
	bool  search(T value)  
	{
		return search (root,value);
	}
	void remove(T value);

	Node<T>* search5(T value){return new Node<T>();}
	Node<T>* searchNew(T value);//{return new Node<T>();}

private:
	void add(Node<T> * current, T val);
	bool  search(Node<T>* current, T val);
};

//template <class T>
//Tree<T>::Node<T>* SearchTree<T>::searchNew(T value)
//{
//	return new Node<T>();
//}


template <class T> 
void SearchTree<T>::add(T val)
{
	// add value to binary search tree 
	if (!root)
	{
		root = new Node<T>(val);
		return;
	}
	add(root,val);
}

template <class T> 
bool SearchTree<T>::	search(Node<T> * current,T val) 
{
	// see if argument value occurs in tree
	if(!current)
		return false;	// not found
	if (current->value == val)
		return true;
	if (current->value < val)
		return search (current->right,val);
	else
		return search (current->left,val);
}

template <class T> 
void SearchTree<T>::add(Node<T>* current, T val)
{
	if (current->value < val)
		// add to right subtree
			if (!current->right)
			{
				current->right=new Node<T>(val);
				return;
			}
			else add(current->right,val);
	else
		// add to left subtree
		if (!current->left)
		{
			current->left=new Node<T>(val);
			return;
		}
		else add(current->left,val);
}

template <class T> 
void SearchTree<T>::remove(T val)
{
	//HOME WORK!
} 


#endif