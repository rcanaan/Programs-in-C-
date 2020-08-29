#include "Clock.h"
#include "Account.h"
#include <iostream>
#include <string>
using namespace std;

int Account::sumWithdraw = 0; // static varible
int Account::sumDeposit = 0;  // static varible


Account::Account()//default constructor
{
	accountNumber = 0;
	code = 0;
	balance = 0;
}

Account::Account(int acn, int c, float b)//constructor
{
	accountNumber = acn;
	code = c;
	balance = b;
}

Account::~Account()//destructor
{
}

void Account::setACN(int acn)//setting accountNumber
{
	accountNumber = acn;
}

void Account::setCode(int c)//setting code
{
		try 
		{
			if ((c / 1000) == 0)//in case it is less than for digits
				throw "ERROR: code must be of 4 digits! \n";
			else//in case the intered code is correct
				code = c;
		}
	
		catch (string strg)
		{
			cout << strg << endl;
		}
}

int Account::getACN() const//getting account number
{
	return accountNumber;
}

int Account::getCode() const
{
	return code;
}

float Account::getBal() const
{
	return balance;
}

void Account::withdraw(float nis)//withdrawing money from the bank account
{
	float combinedMoney = balance - nis;
	//try
	//{
		//if ((nis <= 2500) && (combinedMoney >= -6000))//if the balance at the proper range and also the nis
		//{
		//	balance -= nis;//reducing the cash
		//	sumWithdraw += nis;
		//	return;
		//}
		if (combinedMoney < -6000)
			throw "ERROR: cannot have less than - 6000 NIS! \n";
		else
		{
			if (nis > 2500)//exception from the permitted
				throw "ERROR: cannot withdraw more than 2500 NIS! \n";

			else
			{
				balance -= nis;//reducing the cash
				sumWithdraw += nis;
				return;
			}
			
			//if (combinedMoney < -6000)//exception from the permitted
			//throw "ERROR: cannot have less than - 6000 NIS! \n";
		}
	//}

	/*catch (string c)//MAIN
	{
		cout << c << endl;
	}*/
}

void Account::deposit(float cheque)//deposit cheques at the bank account till 10000 nis
{
	/*try 
	{*/
		if (cheque <= 10000)
		{
			balance += cheque;//updating balance
			sumDeposit += cheque;
		}
		else
		{
			throw "ERROR: cannot deposit more than 10000 NIS! \n";
			
		}
	//}
	/*catch (string a)//MAIN
	{
		cout << a << endl;
	}*/
}

istream & operator>>(istream & is, Account & a)//reading the account details
{
	int tempAC, tempC;//account number, code
	
	is >> tempAC >> tempC;//reading the temp values
//	int code4digits = tempC/1000
	//try
	//{
		if (((tempC/1000) == 0) ||((tempC/1000) > 9))	//in case it is less than for digits
			throw "ERROR: code must be of 4 digits! \n";
		else//in case the intered code is correct
			a.code = tempC;

		
	//}

	//catch (string strg)//MAIN
	//{
	//	cout << strg << endl;
	//}

	a.balance = 0;//calibrating the balance at the bank account
	a.accountNumber = tempAC;//updating the account number
}

//static func
int Account::getSumWithdraw()
{
	return sumWithdraw;
}
int Account::getSumDeposit()
{
	return sumDeposit;

}