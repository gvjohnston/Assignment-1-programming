#include "stack.h"
#include <string>
#include <iostream>
#include <iomanip> //contains setw(n)

using namespace std;

stack StackInput(string intName){

	stack StackInt(50);
	string input;

	cout << "Please enter your " << intName << " integer; - to end or ! to restart the integer:" << endl;

	while (true)
	{
		cin >> setw(1) >> input; // Sets the field width of cin and places keypress into "input"
		if (input == "-"){ // If input is the end input character
			return StackInt; //returns the stack and exits.
//			StackInt.~stack();
			break;
		}
		else if (input == "!"){ //If input is the restart character
//			StackInt.~stack(); //Deconstructs stack
			stack StackInput(string(intName)); //recalls this function with a pointer to intName and exits.
			break;
		}

		else if (!StackInt.Push(stoi(input))){ //If push returns false, the array is full
			cout << endl << "The Array is full. Continuing with the first 50 numbers." << endl;
			return StackInt;
//			StackInt.~stack();
			break;
		}
	}
}


int main(){
	stack FirstInt = StackInput("first");
	stack SecondInt = StackInput("second");
//	FirstInt.~stack();
//	SecondInt.~stack();
	return 0;
}