#pragma once
#include <iostream>
using namespace std;

class Account//defining the Account class
{
private:
	int accountNumber;//the number of the account at the bank
	int code;//the code to the account. will be 4 digits only. MSB not 0.
	float balance;// the "yitra" at the account
	static int sumWithdraw;
	static int sumDeposit;

public:
	Account();//default constructor
	Account(int, int, float);//constructorr
	~Account();//destructor

	static int getSumWithdraw();
	static int  getSumDeposit();

	void setACN(int acn);//setting accountNumber
	void setCode(int c);//setting code

	int getACN()const;
	int getCode()const;
	float getBal() const;

	friend istream & operator >> (istream &is, Account & a);//reading the account details

	void withdraw(float nis);//withdrawing money from the bank account
	void deposit(float);//deposit cheques at the bank account till 10000 nis

	
};
