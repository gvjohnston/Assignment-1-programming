#include "stack.h"
#include <string>
#include <iostream>
#include <iomanip> // contains setw(n)

using namespace std;
bool Switched = false; // Holds whether the arrays were switched
bool borrowed = false; // Flags a borrow has taken place. Declared globally so iterative calls can take place without resetting flag.

bool header()
{
	cout << "====================================================" << endl
		<< " All input must be followed by enter." << endl
		<< " Numbers split onto multiple lines are permitted." << endl
		<< "====================================================" << endl << endl;
	return true;
}

stack StackInput(string intName){

	stack StackInt;
	string input;
	bool error = false;

	cout << " Please enter your " << intName << " integer; = to end or ! to restart the integer:" << endl;

	while (true)
	{
		cin >> setw(1) >> input; // Sets the field width of cin and places keypress into "input"
//		cout << input; //debug
		if (input == "-") //if the input is a - it is assumed that the user is attempting to enter a -ve number.
		{
			cout << endl << "Negative numbers are not supported :(" << endl;
			StackInt.~stack(); //Deconstructs stack
			return StackInput(string(intName)); //recalls this function and exits.
		}
		else if (input == "=") // If input is the end input character
		{
			return StackInt; //returns the stack and exits.
			break;
		}
		else if (input == "!") //If input is the restart character
		{ 
			StackInt.~stack(); //Deconstructs stack
			return StackInput(string(intName)); //recalls this function and exits.
			break;
		}
		else if (!StackInt.Push(stoi(input))) //If push returns false, the array is full
		{
			cout << endl << "The Array is full. Continuing with the first 50 numbers." << endl;
			return StackInt;
			break;
		}
		else if (!stoi(input))
		{
			cout << endl << "Unexpected input. Only '=', '!', and 0-9 are accepted" << endl;
			return StackInput(string(intName)); //recalls this function and exits.
		}

//		else if (!StackInt.Push(stoi(input))) //If push returns false, the array is full
//		{
//			cout << endl << "The Array is full. Continuing with the first 50 numbers." << endl;
//			return StackInt;
//			break;
//		}
	}


}

bool stackSwap(stack& stack1, stack& stack2) // Swaps two stacks
{
	stack temp = stack1;
	stack1 = stack2;
	stack2 = temp;
	Switched = true;
	return true;
}

stack elementCompare(int &indexFirst, int &indexSecond, stack &Stack1, stack &Stack2) //Compares the two interger stacks elementwise. Declared in its own function as it can run recursively 
{

	int elementFirst = Stack1.getElement(0);
	int elementSecond = Stack2.getElement(0);
	if (elementFirst > elementSecond)
	{
		return Stack1, Stack2; // Stack1 is greater
	}
	else if (elementFirst < elementSecond)
	{
		stackSwap(Stack1, Stack2); //Stack2 is greater. Swap stacks and return
		Switched = true; //pointless function for breakpoint in debug
	}
	else if (elementFirst == elementSecond)
	{
		indexFirst++;
		indexSecond++;
		if (indexFirst != 1 & indexSecond != -1)
		{
			elementCompare(indexFirst, indexSecond, Stack1, Stack2);
		}
		else
		{
			return Stack1, Stack2; // the numbers are identical
		}
	}
}

bool compare(stack &Stack1, stack &Stack2) //Compares the length of two interger stacks
{
	int indexFirst = Stack1.getIndex();
	int indexSecond = Stack2.getIndex();

	if (indexFirst > indexSecond)
	{
		return true; // Stack1 is greater.
	}
	else if (indexFirst < indexSecond)
	{
		
		stackSwap(Stack1, Stack2); //Stack2 is greater. Swap stacks and return
		return true;
	}
	else if (indexFirst == indexSecond)
	{
		elementCompare(indexFirst, indexSecond, Stack1, Stack2);
		return true;
	}
	else
	{
		return false; //If the code reaches this line an error has occurred.
	}
}

bool calculate(stack &stack1, stack &stack2, stack &answer) //does the subtraction and stores the answer with the most significant digit on top
{
	int digitFirst;
	int digitSecond;

	while ((stack1.getIndex() > -1) & (stack2.getIndex() > -1))
	{
		stack1.Pop(digitFirst);
		stack2.Pop(digitSecond);

		if (borrowed) //if the last itteration borrowed from this itteration
		{
			digitFirst = digitFirst - 1;
			borrowed = false;
		}
		if (digitFirst < digitSecond)
		{
			digitFirst = digitFirst + 10; //borrows 10 units from next digit. Will get subtracted next iteration.
			borrowed = true; //flags the borrow
		}
		answer.Push((digitFirst - digitSecond));

	}
	return true;
}

bool output(stack answerInt)
{
	int element;
	bool start = true; //true if cout has not recieved a non 0 value yet

	cout << "The answer is:" << endl;
	if (Switched) //if the arrays have been switched print a negative sign
	{
		cout << "-";
	}
	while (!answerInt.Empty()) //while the answer stack is not empty
	{
		answerInt.Pop(element);
		if (element != 0 || start == false) //if element is a zero and we are at the start of the output the element is not printed
		{
			cout << element;
			start = false;
		}
	}
	cout << endl;
	return true;
}

int main()
{
	header(); //A nicely formatted intructions header

	stack firstInt = StackInput("first"); //StackInput prompts for first integer and returns stack for assignment to firstInt
	stack secondInt = StackInput("second"); //StackInput prompts for second integer and returns stack for assignment to secondInt
	stack answerInt; //Initialisation of the stack which will hold the answer

	compare(firstInt, secondInt); //Compares the two stacks and sets firstInt to be the biggest stack
	calculate(firstInt, secondInt, answerInt); //Calculates the difference and stores the answer in answerInt
	output(answerInt); //prints the answer neatly to console

	cin.ignore(); //IDE immediately closes the console after output so this line holds the console open until a button is pressed
	return 0;
}
