
/* Name: Andrew Stade
Date: 10/22/2020
Section: COP 4530 */

#include "stack.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
using namespace cop4530;

int checkSign(string str);			// Return differing values based on operator
bool checkAlnum(string str);		// Tests if character is alphanumeric
void computePostfix(vector<string> &infix, vector<string> &outVector);
void evaluatePostfix(vector<string> &outVector);
void print(vector<string> &outVector);

int main()
{
	vector<string> inVector;		// Vector to input data
	vector<string> outVector;		// Vector to ouput data
	string input;
	
	
	while(input != "end" && input != "exit")
	{	
		cout << "*IN2POST.CPP* (type 'exit' or 'end')" << endl;
		cout << "Enter infix expression: " ;
	
		getline(cin, input);

		outVector.clear();			// Clear old data
		inVector.clear();
		stringstream sstream(input);
		
		while (sstream >> input)		// Used for tokens
		{
			inVector.push_back(input);
		}
		
		cout << "Postfix expression: ";
		computePostfix(inVector, outVector);
		
		cout << "Postfix evaluation: ";
		evaluatePostfix(outVector);
	}
	
	cout << "Shutting Down" << endl;
	
	return 0;
}

int checkSign(string str)		// Return differing values based on operator
{
	if(str == "(" || str == ")")
	{
		return (3);
	}
	else if(str == "*" || str == "/")
	{
		return (2);
	}
	else if(str == "+" || str == "-")
	{
		return (1);
	}
	else
	{
		return 0;
	}
}

bool checkAlnum(string str)		// Check if character is alphanumeric
{
	for(int i = 0; i < int(str.size()); i++)
	{
		if(isalnum(str[i]) == false)			// C++ reference
		{
			return false;
		}
	}
	
	return true;
}

void computePostfix(vector<string> &infix, vector<string> &outVector)		// help from recitations
{
	Stack<string> s;														// basically: check sign -> parenthesis || alnum || empty
	
	for(int i = 0; i < int(infix.size()); i++)
	{
		if(checkSign(infix[i]) != 0)
		{
			if(((s.empty() == false) && (s.top() != "(")) && (checkSign(s.top()) >= checkSign(infix[i])))
			{
				while (((s.empty() == false) && (s.top() != "(")) && (checkSign(s.top()) >= checkSign(infix[i])))
				{
					outVector.push_back(s.top());
					cout << s.top() << " ";
					s.pop();
				}
			}
			s.push(infix[i]);
			
			if(infix[i] == ")")		// Parenthesis check
			{
				s.pop();
				while(s.top() != "(")
				{
					cout << s.top() << " ";
					outVector.push_back(s.top());
					s.pop();
				}
				s.pop();
			}
		}
		else if(checkAlnum(infix[i]) == true)
		{
			outVector.push_back(infix[i]);
			cout << infix[i] << " ";
		}
	}
	while(s.empty() == false)
	{
		cout << s.top() << " ";
		outVector.push_back(s.top());
		s.pop();
	}
	cout << endl;
}

void evaluatePostfix(vector<string> &outVector)			// Error: Incorrectly calculates postfix in some instances
{
	Stack<string> stack;
	bool checkNum = false;
	
	for(int i = 0; i < int(outVector.size()); i++)			// first check if alnum, then digit
	{
		if(checkAlnum(outVector[i]) == true)
		{
			for(int j = 0; j < int(outVector[j].size()); j++)
			{
				if(isdigit(outVector[i][j]) == true)
				{
					checkNum = true;
				}
				else
				{
					break;
				}
			}
		}
	}
	if(checkNum == true)								// alnum -> sign -> print
	{
		for(int i = 0; i < int(outVector.size()); i++)
		{
			if(checkAlnum(outVector[i]) == true)		// push to stack if alnum
			{
				stack.push(outVector[i]);
			}
			if(checkSign(outVector[i]) != 0)			// string to float conversion
			{
				float temp;
				float first = stof(stack.top());		// Error: automatically aborts if invalid arguments
				stack.pop();
				float second = stof(stack.top());
				stack.pop();
				
				if(outVector[i][0] == '*')				// compute operators
				{
					temp = second * first;
				}
				else if(outVector[i][0] == '/')
				{
					temp = second / first;
				}
				else if(outVector[i][0] == '+')
				{
					temp = second + first;
				}
				else if(outVector[i][0] == '-')
				{
					temp = second - first;
				}
				stack.push(to_string(temp));		// float to string conversion
			}
		}
		print(outVector);
		cout << "= " << stack.top() << endl;
	}
	else	// not an int (?)
	{
		print(outVector);
		cout << "= ";
		print(outVector);
		cout << endl;
	}
}

void print(vector<string> &outVector)			// print
{
	for(int i = 0; i < int(outVector.size()); i++)
	{
		cout << outVector[i] << " ";
	}
}
