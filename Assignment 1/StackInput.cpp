#include <iostream>
#include <iomanip> //contains setw(n)
#include "stack.h"

using namespace std;

stack StackInput(){
	stack StackInt(50);
	int input;
	while (true)
	{
		cin >> setw(1) >> input; //sets the field width of cin
		if (input = -1){
			return StackInt;
			break;
		}
		else if (!StackInt.Push(input)){ //If push returns false, the array is full
			cout << "The Array is full. Continuing with the first 50 numbers";
			return StackInt;
			break;
		}
	}
}
