#include "stack.h"

// Constructor

stack :: stack(int stacksize) :
StackSize(stacksize),
Contents(new int[stacksize]),
IndexOfTop (-1)
{}

// Destructor

stack :: ~stack()
{
  delete [] Contents;
}

// Tests

bool stack :: Empty() const
{
  return (IndexOfTop == -1) ? true : false;
}

bool stack :: Full() const
{
  return (IndexOfTop == StackSize - 1) ? true : false;
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