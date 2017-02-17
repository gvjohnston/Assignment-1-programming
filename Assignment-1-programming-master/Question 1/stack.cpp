#include "stack.h"

// Constructor

stack :: stack() : IndexOfTop (-1)
{}

// Tests
bool stack :: Empty() const
{
  return (IndexOfTop == -1) ? true : false;
}

bool stack :: Full() const
{
  return (IndexOfTop == MAXSTACKSIZE - 1) ? true : false;
}

// Pop and Push

bool stack :: Pop(int& TopElement)
{
  if (Empty()) 
    return false;
  else
  {
    TopElement = Contents[IndexOfTop];
    IndexOfTop--;
    return true;
  }
}

bool stack :: Push(const int& NewElement)
{
  if (Full()) 
    return false;
  else
  {
    IndexOfTop++;
    Contents[IndexOfTop] = NewElement;
    return true;
  }
}

//Additions by GJ

int stack :: getIndex() //returns the index
{
	return IndexOfTop;
}

int stack :: getElement(int index) //returns the element at position index
{
	return Contents[index];
}