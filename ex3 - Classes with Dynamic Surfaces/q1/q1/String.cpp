#include "String.h"
#include <cstring>
#include <iostream>
using namespace std;


String::String(char * s)//constructor + default constructor
{
	int size = strlen(s) + 1;
	str = new char[size];//setting  length
//	strcpy_s(str,size, s);//copy
	strcpy(str, s);

}
String::String(const String & strg)//copy constructor
{
	int size = strlen(strg.str) + 1;
	str = new char[size];//setting length
	//strcpy_s(str,size ,strg.str);//copy
	strcpy(str, strg.str);
}

char  * String::getString() const
{
	return str;
}
//String & String::operator = (const String & rhs)//setting operation
//{
//	if (str != nullptr)//if there is data inside str
//		delete[] str;
//	str = new char[strlen(rhs.str) + 1];//setting length (+1 for the "\0)
//	strcpy(str, rhs.str);//concatenating
//	return *this;
//}


String String ::operator +(String & rhs)//adding two strings into another
{
	int size = strlen(str) + strlen(rhs.str) + 1;
	char * temp;//new string that will get the combination of the two other strings
	temp = new char[size];//setting length
	//strcpy_s(temp,size, str);//copying the first word into temp
	strcpy(temp, str);
	//strcpy_s(temp + strlen(str),size, rhs.str);//pointing to the middle of the string, and there adding the new string
	strcpy(temp + strlen(str), rhs.str);
	String tempStr(temp);
	return tempStr;
}

void String:: operator < (const String & rhs)//if a<b
{
	if ((strcmp(str, rhs.getString())) < 0)
		cout << "a<b" << endl;
}
void String:: operator > (const String & rhs)// if a>b
{
	if ((strcmp(str, rhs.getString())) > 0)
		cout << "a>b" << endl;
}
void String::operator = (String  & rhs)
{
	if (strcmp(str, rhs.getString()) == 0)   //a =b
		cout << "a=b" << endl;
}

bool String:: operator >= (String & rhs)
{
	if ((((strcmp(str, rhs.getString())) > 0) || ((strcmp(str, rhs.getString())) == 0)))//a>=b
	{
		return true;
	}
	return false;
}

bool String:: operator<= (String & rhs)
{
	if (((strcmp(str, rhs.getString())) < 0) || ((strcmp(str, rhs.getString())) == 0))//a<=b
		return true;
	else
		return false;
}
bool String:: operator != ( String & rhs)
{
	if (((strcmp(str, rhs.getString())) < 0) || ((strcmp(str, rhs.getString())> 0)))//a!=b
		return true;
	return false;

}
void String::print_str()
{
	cout << str << endl;

}


String  String::insert(int index, const char * strg)//adding the new str to the old one from the wanted index
{
	if (index <= strlen(strg))//if the index compatable to the length of the string
	{
		int size = strlen(str) + strlen(strg) + 1;
		char * tmp = new char[size];          //create arrary for the length of two string  +1 for \0         
		//strncpy_s(tmp, size, str, index);//just like strcpy but copy specific letters- till wanted index
		strncpy(tmp, str, index);
		tmp[index] = '\0';  // ending the first word
		//strcat_s(tmp,size ,strg); // add the second string after the "\0"
		//strcat_s(tmp,size, str + index);//go back and copy what is remained from the first string (because the first string got splited)
		strcat(tmp, strg);
		strcat(tmp, str + index);
		String Tmp(tmp);
		return Tmp;
	}
	else
	{
		cout << "ERROR"<<endl;
		str = nullptr;
	}
}

String::~String()//destructor
{
	if (str)
		delete[] str;
	str = nullptr;
}
