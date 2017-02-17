#include <string>
#include <iostream>

using namespace std;

const int maxSize = 50; // Maximum size of the arrays
bool Switched = false; // Holds whether the arrays were switched


bool header()
{
	cout << "=======================================================" << endl
		<< " All input is processed after enter is pressed." << endl
		<< " Numbers split onto multiple lines are permitted." << endl
		<< " Numbers after the first \"=\" make the second integer." << endl
		<< " Numbers after the second \"=\" are ignored." << endl
		<< "=======================================================" << endl << endl;
	return true;
}

void StackInput(const string& intName, int integer[], int& topIndex) //"first", firstInt[a], a, indexToTop (which will be set in function)
{

	char input;
	int index = 0;

	cout << " Please enter your " << intName << " integer; = to end:" << endl
		<< ">> ";

	for (int i = 0; i < maxSize; i++)
	{
		integer[i] = 0;
		cin.get(input);

		if (input == '=')
		{
			topIndex = index;
			return;
		}
		if (!isdigit(input) && input != '\n')
		{
			cout << endl << "This character: " << input << " is not considered a digit. It is ignored." << endl;
		}
		integer[i] = input;

	}


}

bool arraySwap(int Array1[], int Array2[], int& indexFirst, int& indexSecond) // Swaps two arrays
{
	int temp[maxSize];
	for (int i = 0; i < maxSize; i++)
	{
		temp[i] = Array1[i];
		Array1[i] = Array2[i];
		Array2[i] = temp[i];
	}
		


	int indexTemp = indexFirst;
	indexFirst = indexSecond;
	indexSecond = indexTemp;

	Switched = true;
	return true;
}

bool elementCompare(int Array1[], int Array2[], int indexFirst, int indexSecond) //Compares the two interger, same length, stacks elementwise. 
{
	int i = 0; //common index for the compare loop
	bool equivent = false; // the calculation function will not print anything of the stacks are equivelent so this flag will highlight the case and force output.

	while (i <= indexFirst) // while  i is less than the stack size since the indices are the same; either can be used for the pair
	{
		int elementFirst = Array1[i];
		int elementSecond = Array2[i];

		if (elementFirst > elementSecond)
		{
			return true; // Array1 is greater.
		}
		else if (elementFirst < elementSecond)
		{

			arraySwap(Array1, Array2, indexFirst, indexSecond); //Array2 is greater. Swap stacks and return
			return true;
		}
	i++;
	}
	equivent = true;
	cout << "Stacks are equivalent" << endl; //Debug
}

bool compare(int Array1[], int Array2[], int indexFirst, int indexSecond) //Compares the length of two interger stacks
{

	if (indexFirst > indexSecond)
	{
		return true; // Array1 is greater.
	}
	else if (indexFirst < indexSecond)
	{

		arraySwap(Array1, Array2, indexFirst, indexSecond); //Array2 is greater. Swap stacks and return
		return true;
	}
	else if (indexFirst == indexSecond)
	{
		elementCompare(Array1, Array2, indexFirst, indexSecond);
		return true;
	}
	else
	{
		return false; //If the code reaches this line an error has occurred.
	}
}


bool calculate(int Array1[], int Array2[], int answer[], int index1, int index2, int indexA) //does the subtraction and stores the answer with the most significant digit on top of the stack
{
	int digitFirst = 0;
	int digitSecond = 0;
	bool borrowed = false; // Flags a borrow has taken place.
	int i = 0;

	while ((index1 > -1) || (index2 > -1))
	{
		digitFirst = Array1[index1];

		if (index2 > -1) //While Array2 still has numbers; take numbers from array. If Array2 runs out then add zeros to the start of the number.
		{
			digitSecond = Array2[index2];
		}
		else
		{
			digitSecond = 0;
		}

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
		answer[i] = digitFirst - digitSecond;
		i++;
	}
	indexA = i;
	return true;
}

bool output(int answerInt[], int answerSize)
{
	int element;
	int i;
	bool atStart = true; //true if cout has not recieved a non 0 value yet

	cout << endl << endl << endl << " The answer is: ";

	if (Switched) //if the arrays have been switched print a negative sign
	{
		cout << "-";
	}

	for (i = answerSize; i > -1; i--);
	{
		element = answerInt[i];
		if (atStart == false || element != 0) //if element is a zero and we are at the start of the output the element is not printed
		{
			cout << element;
			atStart = false;
		}
	}
	if (atStart) //if start is still true after the the loop then the answer is 0 and must be printed to avoid an empty answer
	{
		cout << "0";
	}
	cout << "." << endl;
	return true;
}

int main()
{
	header(); //A nicely formatted intructions header

	int firstInt[maxSize];	//Holds the first integer
	int secondInt[maxSize];	//Holds the second integer
	int answerInt[maxSize]; //Holds the answer
	int firstSize;			//
	int secondSize;
	int answerSize = 0;

	StackInput("first", firstInt, firstSize);
	StackInput("second", secondInt, secondSize); //StackInput prompts for second integer and returns stack for assignment to secondInt


	compare(firstInt, secondInt, firstSize, secondSize); //Compares the two stacks and sets firstInt to be the biggest stack
	calculate(firstInt, secondInt, answerInt, firstSize, secondSize, answerSize); //Calculates the difference and stores the answer in answerInt
	output(answerInt, answerSize); //prints the answer neatly to console

	cin.ignore(); //IDE immediately closes the console after output so this line holds the console open until a button is pressed
	return 0;
}
