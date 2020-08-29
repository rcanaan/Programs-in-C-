/*
Rinat Canaan ID 207744012
Course- "workshop at c++"
ex 8 q1
this program calculates the value of equation accroding to the order of operations.
it will do it with a Stack (abstract data type)
*/
#include <iostream>
#include<string>
#include <stack>//adding the library of stack
using namespace std;

string infixToPostfix(string a);//converting from the "infix" method to the "postfix"
int CalcPostfix(string b);//calculating the value of "postfix" equation 
int main()
{
	string exp;
	cout << "enter an infix expression as a string" << endl;
	cin >> exp;
	string postfix = infixToPostfix(exp);
	cout << postfix << endl;
	cout << CalcPostfix(postfix) << endl;

	system("pause");
	return 0;
}

string infixToPostfix(string a)
{
	//(5+3)*((20/10)+(8-6))
	char x, ch;
	bool digit = true;
	bool DoubleDigit = true;
	string str = "";
	int j = 0;
	int r = 0;
	stack <char> stk;//stack
	for (unsigned int i = 0; i < a.length(); i++)
	{
		ch = a[i];//first note from the string

		if ((!isdigit(a[i + 1]) && isdigit(a[i])) || ch == 40 || ch == 41 || ch == '+' || ch == '-' || ch == '*' || ch == '/')//if this is not a double-digit number
		{
			DoubleDigit = false;
			if (isdigit(a[i]))
				digit = true;
		}
		else
		{
			DoubleDigit = true;
			digit = true;
		}
		if ((a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/') && (a[i + 1] == 40) && (isdigit(a[i + 2])))
			r = 1;

		if (ch == 40)//if ch is "("
		{
			stk.push(ch);
			digit = false;
		}
		else if (ch == 41)//if ch is ")"
		{
			x = stk.top();
			while ((x != 40) && (!stk.empty()))//as long the first note at the stack isn't ")" and the stack isn't empty
			{
				if (str[j + 1] != ' ')
					str = str + ' ';//putting space between every to components
				str = str + x; //concatenating
				j++;
				stk.pop();
				if (!stk.empty())
					x = stk.top();//initializing "X" to be first stack's note
			}
			stk.pop();//at the end, extracting the "("
			digit = false;
		}

		else if (ch == '*' || ch == '/') //first preference for mult and division
		{
			if (!stk.empty())
			{
				x = stk.top();
				while ((x == '*' || x == '/') && (!stk.empty()))
				{
					////str = str + ' ';//space
					str = str + x;//concatenating
					j++;
					stk.pop();
					if (!stk.empty())
						x = stk.top();//initializing "X" to be first stack's note
				}
			}
			stk.push(ch);//at the end insert the operator into the stack
			digit = false;

		}
		else if (ch == '+' || ch == '-')
		{
			if (!stk.empty())
			{
				x = stk.top();
				while (x == '+' || x == '-' || x == '*' || x == '/' && !stk.empty())
				{
					////str = str + ' ';//space
					str = str + x;//concatenating
					j++;
					stk.pop();
					if (!stk.empty())
						x = stk.top();//initializing "X" to be first stack's note
				}
			}
			stk.push(ch);
			digit = false;
		}

		else//if ch is a number
		{
			if (digit == true)
			{
				/*if ((str[j + 1] == '+' || str[j + 1] == '-' || str[j + 1] == '*' || str[j + 1] == '/'))
				   str += ' ';*/

				if ((DoubleDigit) && (str[j + 1] == '+' || str[j + 1] == '-' || str[j + 1] == '*' || str[j + 1] == '/')) /*|| ((digit) && (str[j + 1] == '+' || str[j + 1] == '-' || str[j + 1] == '*' || str[j + 1] == '/')))*/
					str = str + ' ';
				else if (r == 1)
				{
					str = str + ' ';
					r = 0;
				}
					

				digit = true;
				str = str + ch;
				j++;
				if (!DoubleDigit)
					str = str + ' ';
			}
			else
			{
				str = str + ch;
				str += ' ';
				j++;

			}

		}
	}
	while (!stk.empty())//copy everything else
	{
		str = str + ' ';//space
		str = str + stk.top();//concatenating
		stk.pop();
	}
	return str;
}


int CalcPostfix(string b)
{
	stack <float> a;//create an enpty stack(A)
	string s = "";//temp string
	float dig, x, y, w, r, z;//will be used to convert from char to integers
	bool d = false;
	for (unsigned int i = 0; i < b.length(); i++)
	{

		if (isdigit(b[i]))//if there are numbers
		{
			s += b[i];
			//s +=b[i+1];//string which only contains numbers
			while (i < (b.length() - 1) && (isdigit(b[i + 1])))//as long there isn't any deviation from the string's size and in case this is a double digit number
			{
				s += b[i + 1];
				i++;
				d = true;
			}
			dig = stoi(s);//converting from char to int the string s
			s = "";
			a.push(dig);
		}

		else if (b[i] == '+' || b[i] == '-' || b[i] == '*' || b[i] == '/' && !a.empty()) // b[i] == operator
		{
			if (d)//if double digit
			{
				w = a.top();
				a.pop();
				r = a.top();
				a.pop();
				//	x = w + r;
				if (b[i] == '*')
					a.push(r * w);
				else if (b[i] == '/')
					a.push(r / w);
				else if (b[i] == '+')
					a.push(r + w);
				else if (b[i] == '-')
					a.push(r - w);
			}
			else

			{
				x = a.top();// first number
				a.pop();
				y = a.top();//second number
				a.pop();



				if (b[i] == '*')
					a.push(x * y);
				else if (b[i] == '/')
					a.push(x / y);
				else if (b[i] == '+')
					a.push(x + y);
				else if (b[i] == '-')
					a.push(x - y);
			}
		}


	}
	return a.top();
}


