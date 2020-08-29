#pragma once
class String//definding the"string" class
{
private:
	char * str;//pointer to an array of chars

public:
	String(char * s = nullptr);//constructor
	String(const String & s);//copy constructor

	char * getString() const;
	//String & operator = (const String &);//placement operator- "operator hasama"
	
	String operator +(String & rhs);

	void operator < (const String &);// a <b
	void operator > (const String &);//a>b
	void operator = (String  & rhs);// a =b
	bool operator >= (String & );//a>=b
	bool operator <= (String & rhs);//a<=b
	bool operator != ( String &);//a!=b
	String  insert(int index, const char * strg);//adding the new str to the old one from the wanted index
	void print_str();//PRINTING






	~String();//destructor
};