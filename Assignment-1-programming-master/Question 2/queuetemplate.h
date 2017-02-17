#ifndef QUEUETEMPLATE_H
#define QUEUETEMPLATE_H
#include "queue.h"

// Constructor

template <class Type>
queue<Type> :: queue(int queuesize) :
QueueSize(queuesize),
Contents(new Type[queuesize + 1]),
Front(0), Back(0)
{}

// Destructor

template <class Type>
queue<Type> :: ~queue()
{
  delete [] Contents;
}

// Tests

template <class Type>
bool queue<Type> :: Empty() const
{
  return (Front == Back) ? true : false;
}

template <class Type>
bool queue<Type> :: Full() const
{
  return ((1 + Back) % (QueueSize + 1) == Front) ? true : false;
}

// Remove and Add

template <class Type>
bool queue<Type> :: Remove(Type& FrontElement)
{
  if (Empty()) 
    return false;
  else
  {
    FrontElement = Contents[Front];
    Front = (Front + 1) % (QueueSize + 1);
    return true;
  }
}

template <class Type>
bool queue<Type> :: Add(const Type& NewElement)
{
  if (Full()) 
    return false;
  else
  {
    Contents[Back] = NewElement;
    Back = (Back + 1) % (QueueSize + 1);
    return true;
  }
}

//Additions by GJ

template <class Type>
int queue<Type> ::getLength() // returns the number of queue elements
{
	return Back - Front;
}

template <class Type>
bool queue<Type> ::findQueueMember(const Type member, int& position) // iteratively  scans Contents for 'member'
{
	for (int i = 0; i < QueueSize; i++)
	{
		if (Contents[i] == member)
		{
			position = i + 1;
			return true;
		}
	}
	return false;
}
#endif
