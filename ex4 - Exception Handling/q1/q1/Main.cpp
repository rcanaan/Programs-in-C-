/*
Rinat Canaan ID 207744012
Course- "workshop at c++"
ex 4 question 1
This program runs an ATM machine.
*/
#include <iostream>
#include"Clock.h"
#include "Account.h"
#include <string>
using namespace std;

enum action
{
	stop,
	balance,
	deposit,
	withdraw,
	sumDeposit,
	sumWithdraw
};
action menu()
{
	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	cout << "enter 4 to see the sum of all withdraws" << endl;
	cout << "enter 5 to see the sum of all Deposits" << endl;
	cout << "enter 0 to stop" << endl;
	int x;
	cin >> x;
	return (action)x;
}
int findAccount(Account* bank, int size);
void printTransaction(Account a, action ac, Clock& c);
void getBalance(Account* bank, int size, Clock& c);
void cashDeposit(Account* bank, int size, Clock& c);
void cashWithdraw(Account* bank, int size, Clock& c);

int main()
{
		Clock c(8, 0, 0);

		Account bank[10];
		cout << "enter account number and code for 10 accounts:\n";
		for (int i = 0; i < 10; i++)
		{
			try 
			{
				cin >> bank[i];
				for (int j = 0; j < i; j++)
					if (bank[i].getACN() == bank[j].getACN())
						throw "ERROR: account number must be unique!\n";// if this account number already exists
			}
			catch (const char* msg)//printing the same time and the error message
			{
				cout << c << '\t' << msg << endl;
				i--;
			}
		}
		
		action ac = menu();
		while (ac)
		{
			try 
			{
				switch (ac)
				{
				case balance: getBalance(bank, 10, c);
					break;
				case withdraw:cashWithdraw(bank, 10, c);
					break;
				case deposit:cashDeposit(bank, 10, c);
					break;
				case sumDeposit:c += 60;
					printTransaction(bank[0], sumDeposit, c);
					break;
				case sumWithdraw:c += 60;
					printTransaction(bank[0], sumWithdraw, c);

				}
				//ac = menu();
			}
			catch (const char * str)
			{
				cout << c << '\t' << str << endl;
			}
			ac = menu();
		}

	system("pause");
	return 0;

}




int findAccount(Account* bank, int size)
{
	int number, code;
	cout << "please enter account number: ";
	cin >> number;
	int i = 0;
	while (i < size && bank[i].getACN() != number)
		i++;

	if (i == size)
		return -1;

	cout << "please enter the code: ";
	cin >> code;
	if (bank[i].getCode() != code)
		return -2;

	if (bank[i].getCode() == code)
		return i;
	
	//try 
	//{
	//	if (i == size)
	//	{
	//		/*printTransaction(bank[i], balance, c);*/
	//		string str = "ERROR: no such account number! \n";
	//		throw str;
	//	}
	//}
	//catch (string str)
	//{
	//	cout << str;
	//}
	//cout << "please enter the code: ";
	//cin >> code;
	//if (bank[i].getCode() == code)
	//	return i;
	//return -1;
}
void printTransaction(Account a, action ac, Clock& c)
{
	cout << c << "\t";
	
	switch (ac)
	{
	case balance: cout << "account #: " << a.getACN() << "\t";
		cout << "balance: " << a.getBal() << endl;
		break;
	case deposit:
	case withdraw: cout << "account #: " << a.getACN() << "\t";
		cout << "new balance: " << a.getBal() << endl;
		break;
		case sumDeposit:
			cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
			break;
		case sumWithdraw:
			cout << "sum of all withdraws: " << Account::getSumWithdraw() << endl;
			break;
	}
}
void getBalance(Account* bank, int size, Clock& c)
{
	/*int i = findAccount(bank, size);
	c += 20;
	printTransaction(bank[i], balance, c);*/

	int i = findAccount(bank, size);

	/*try
	{*/
		if (i == -1)
		{
			/*cout << c << "\t";*/
			throw "ERROR: no such account number!\n";

		}
		else if (i == -2)
		{
			/*cout << c << "\t";*/
			throw "ERROR: wrong code!\n";

		}
		if (i >= 0)
		{
			c += 20;    // there is no exeptions, so update the time. 
			printTransaction(bank[i], balance, c);
		}

		/*catch (const char * s)//MAIN
	{
		cout << s << endl;
	}*/

}
	

void cashDeposit(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size);
	float amount;


	if (i == -1)
	{
		/*cout << c << "\t";*/
		throw "ERROR: no such account number!\n";
		
	}
	if (i == -2)
	{/*
		cout << c << "\t";*/
		throw "ERROR: wrong code!\n";
	}
	if (i >= 0)
	{
		cout << "enter the amount of the check: ";
		cin >> amount;
		bank[i].deposit(amount);
		c += 30;
		printTransaction(bank[i], deposit, c);
	}



}
void cashWithdraw(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size);
	float amount;

	if (i == -1)
	{
		/*cout << c << "\t";*/
		throw "ERROR: no such account number!\n";
	}
	if (i == -2)
	{/*
		cout << c << "\t";*/
		throw "ERROR: wrong code!\n";
	}
	if (i >= 0)
	{
		cout << "enter the amount of money to withdraw: ";
		cin >> amount;
		bank[i].withdraw(amount);
		c += 50;
		printTransaction(bank[i], withdraw, c);
	}
}

