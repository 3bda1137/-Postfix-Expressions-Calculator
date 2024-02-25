
#include <iostream>
#include <iomanip>
#include <fstream>
#include "MyStack.h"
using namespace std;

void evaluateOpr(ofstream& out, MyStack<double>& stack,
	char& ch, bool& isExpOk)
{
	double op1, op2;

	if (stack.IsEmpty())
	{
		out << " (Not enough operands)";
		isExpOk = false;
	}
	else
	{
		op2 = stack.Top();
		stack.Pop();
		if (stack.IsEmpty())
		{
			out << " (Not enough operands)";
			isExpOk = false;
		}
		else
		{
			op1 = stack.Top();
			stack.Pop();
			switch (ch)
			{
			case '+':
				stack.Push(op1 + op2);
				break;
			case '-':
				stack.Push(op1 - op2);
				break;
			case '*':
				stack.Push(op1 * op2);
				break;
			case '/':
				if (op2 != 0)
					stack.Push(op1 / op2);
				else
				{
					out << " (Division by 0)";
					isExpOk = false;
				}

				break;
			default:
				out << " (Illegal operator)";
				isExpOk = false;
			}
		}
	}
}
void discardExp(ifstream& in, ofstream& out, char& ch)
{
	while (ch != '=')
	{
		in.get(ch);
		out << ch;
	}
}
void evaluateExpression(ifstream& inpF, ofstream& outF,MyStack<double>& stack,char& ch, bool& isExpOk)
{
	double num;
	outF << ch;
	while (ch != '=')
	{
		switch (ch)
		{
		case '#':
			inpF >> num;
			outF << num << " ";
			if (!stack.IsFull())
				stack.Push(num);
			else
			{
				cout << "Stack overflow. "
					<< "Program terminates!" << endl;
				exit(0);
			}
			break;
		default:
			evaluateOpr(outF, stack, ch, isExpOk);
		}//end switch
		if (isExpOk) //if no error
		{
			inpF >> ch;
			outF << ch;
			if (ch != '#')
				outF << " ";
		}
		else	
		discardExp(inpF, outF, ch);
	}
}




void printResult(ofstream& outF, MyStack<double>& stack,
	bool isExpOk)
{
	double result;
	if (isExpOk) //if no error, print the result
	{
		if (!stack.IsEmpty())
		{
			result = stack.Top();
			stack.Pop();
			if (stack.IsEmpty())
				outF << result << endl;
			else
				outF << " (Error: Too many operands)" << endl;
		} //end if
		else
			outF << " (Error in the expression)" << endl;
	}
	
	else
		outF << " (Error in the expression)" << endl;
	outF << "_________________________________"<< endl << endl;
}
int main()
{
	bool expressionOk;
	char ch;
	MyStack<double>* stack = new MyStack<double>();  // Allocate memory for MyStack object
	ifstream infile;
	ofstream outfile;
	infile.open("Input.txt");
	if (!infile)
	{
		cout << "Cannot open the input file. " << "Program terminates!" << endl;
		delete stack;  // Free the allocated memory
		return 1;
	}

	outfile.open("Output.txt");
	outfile << fixed << showpoint;
	outfile << setprecision(2);
	infile >> ch;
	while (infile)
	{
		stack->Initialization();  // Use -> to access members and methods of the stack pointer
		expressionOk = true;
		outfile << ch;
		evaluateExpression(infile, outfile, *stack, ch, expressionOk);  // Pass the dereferenced stack
		printResult(outfile, *stack, expressionOk);  // Pass the dereferenced stack
		infile >> ch; //begin processing the next expression
	}

	infile.close();
	outfile.close();
	delete stack;  // Free the allocated memory
	return 0;
}
