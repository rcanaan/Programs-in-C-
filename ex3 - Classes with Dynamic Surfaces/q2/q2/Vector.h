#pragma once
class Vector//defining the class "Vector"
{
private:
	int * data;//pointer to vector with ints
	int capacity;// the max length of the vector
	int size;//the actual size of the vector

public:
	Vector();//default constructor
	Vector(int );//constructor 
	Vector(const Vector &);//copy constructor
	
	int getCapacity() const;//returning the amount  of existing number at vec
	int getSize() const;
	int * get_data() const;
	void set_data(int*);

	void print() const;//printing the vec details
	
	Vector & operator = (const Vector &);////placement operator- "operator hasama"
	bool operator == (Vector &);//bool ==
	int & operator [] (int);//operator []
	int operator * (Vector &);//
	Vector operator + (Vector &);

	void clear();//nulling the vector from
	void delLast();//deleting  the last 
	void insert(int val);//putting "val" at the next empty cell

	


	~Vector(void);//destructor
};