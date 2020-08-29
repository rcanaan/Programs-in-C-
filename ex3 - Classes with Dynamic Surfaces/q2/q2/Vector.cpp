#include <iostream>
#include"Vector.h"
using namespace std;

Vector::Vector()//default constructor
{
	capacity = 10;//as we were asked to do 
	data = new int[capacity];
	size = 0;
}
Vector::Vector(int capacity)//constructor
{
	this->capacity = capacity;
	data = new int[capacity];
	size = 0;
}
Vector::Vector(const Vector & vec)//copy constructor
{
	capacity = vec.capacity;
	size = vec.size;
	data = new int[capacity];
	for (int i = 0; i < size; i++)
		data[i] = vec.data[i];//copying all the numbers from vec to data
}
int Vector::getCapacity() const//returning the amount  of existing number at vec
{
	return capacity;
}
int Vector::getSize() const
{
	return size;
}
int * Vector::get_data() const
{
	return data;
}
void Vector::print() const//printing the vec details
{
	cout << "capacity: " << capacity << " size: " << size << " val: ";
	for (int i = 0; i < size; i++)
		cout << data[i] << " ";
	cout << endl;
}

Vector & Vector::operator=(const Vector & vec)//placement operator- "operator hasama"
{
	if (data != nullptr)//if there is data inside "data"
		delete[] data;
	data = new int[vec.capacity];//setting max length - as the capacity of vec
	size = vec.size;
	for (int i = 0; i < vec.size; i++)
	{
		data[i] = vec.data[i];//copy from vec to "this", data
	}
	return *this;
}
bool Vector::operator==(Vector & vec)//if the two arraeys equale
{
	int count = 0;
	//if (capacity = vec.capacity)
		if (size = vec.size)//if the sizes are identify
		{
			for (int i = 0; i < size; i++)
				if (data[i] == vec.data[i])//if the data are equale
					count++;//than count
			if (count == size)//if all the numbers at both arrays are identify, it means that count = suze
				return true;
			return false;
		}
	return false;

}
int & Vector::operator[](int index)//setter and getter of an specific value
{
	if (index > size)//if the wanted index is not suitable to the "data" length
		cout << "ERROR" << endl;
	else//if it does fit 
		return data[index];
}
int Vector::operator*(Vector & vec)//doing scalar multing between the two vectors
{
	int result = 0;
	if (size != vec.size)//if the length doesn't fit
		cout << "ERROR" << endl;
	else
		for (int i = 0; i < size; i++)
			result =result + (data[i] * vec[i]);//multing and adding the result every time
	return result;
}
Vector Vector::operator+(Vector & vec)//concatenating the two vectors into the new onr
{
	//Vector Temp(10);
	//int * tmp;//creating the new vector
	////int sizeTmp = size + vec.size;//the length of the new vector
	//tmp = new int[capacity];
	//for (int i = 0; i < size; i++)
	//	Temp.data[i] = data[i];//concatenating the first vector to temp
	//for (int i = size + 1; i < capacity; i++)
	//	Temp.data[i] = vec.data[i];
	//return Temp;
	Vector A(10);
	int *result = new int[capacity];
	//get_data()
	for (int i = 0; i < size; i++)
	{
		A.data[i] = data[i];           // copy the exsist vector in the begining .....               
		A.data[i + size] = vec.data[i];    //... add the new vector after the first one                 
	}

	A.size = (vec.size) * 2;         // update the array size

	return A;



}

void Vector::clear()
{
	for (int i = 0; i < size; i++)
		data[i] = 0;
	size = 0;

}
void Vector::delLast()
{
	int count = 0;
	for (int i = 0; i < size; i++)
		if (data[i] == 0)
			count++;
	if (count == size)//if the vector does empty
		cout << "ERROR" << endl;
	else
		data[size] = 0;//nulling
	size--;//deleting the last limb

}
void Vector::insert(int val)
{
	//int count = 0;
	//for (int i = 0; i < size; i++)
	//{
	//	if (data[i] == NULL)//if the cell is empty
	//	{
	//		data[i] = val;
	//		return;
	//	}
	//	count++;//to check how many cells are full
	//}
	//if (count == size)//is the vector is full
	//	cout << "ERROR" << endl;
	*data = val;
	data++;
	size++;

}
void Vector::set_data(int* p)
{
	data = p;

}




Vector::~Vector(void)//destructor
{
	if (data)
		delete[] data;
	data = NULL;//nullptr;//NULL
}
