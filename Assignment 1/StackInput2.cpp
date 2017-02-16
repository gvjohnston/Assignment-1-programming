#include <string>
#include <iostream>
#include <iomanip> // contains setw(n)

using namespace std;
bool Switched = false; // Holds whether the arrays were switched
bool borrowed = false; // Flags a borrow has taken place. Declared globally so iterative calls can take place without resetting flag.

void StackInput(const string& intName, int& integer[], const int& maxSize, int& topIndex)) //"first", firstInt[a], a, indexToTop (which will be set in function)
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
			topIndex = index
			return
		}
		if (!isdigit(input))
		{
			cout << endl << "This character: " << input << " is not considered a digit. It is ignored." << endl;
		}
		integer[i] = input;

	}


}
	// function read_int_as_array
	// 
	// parameter input: array to hold the digits of the integer
	// parameter size: the size of the array
	// parameter numdigits: the number of digits of the integer read in
	// parameter success: indicates that integer was read successfully,
	// or otherwise.
	//
	//
	// This function reads an integer of up to "size" digits
	// and stores the digits in the array "input".
	//


	void read_int_as_array(int input[], int size, int& numdigits, bool& success)

	{
		char temp;
		int i;
		success = true;
		if (size < 1) return;

		int count = 0;

		// initialise array entries to 0

		for (i = 0; i < size; i++)
			input[i] = 0;

		do
			// loop through input characters
		{
			// get character
			cin.get(temp);
			// if we have not reached end of line or got too many digits
			// place digit into array, converted to int
			if ((temp != '\n') && (count < size))
				input[count] = int(temp) - int('0');
			// if the character was not a digit, make success false
			if ((!isdigit(temp)) && (temp != '\n'))
				success = false;

			// increase counter
			count++;
		} while (temp != '\n');

		// set numdigits to avoid counting the end of line character
		numdigits = count - 1;

		// if there were too many digits, set success to false
		if (numdigits > size)
			success = false;
		return;


	}

