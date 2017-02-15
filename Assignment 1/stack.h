#ifndef STACK_H
#define STACK_H

// Simple integer stack with fixed sized array implementation with additions by GJ

const int MAXSTACKSIZE = 50;

class stack
{
private:
  int Contents[MAXSTACKSIZE];
  int IndexOfTop;
public:
  stack();
  bool Empty() const;
  bool Full() const;
  bool Pop(int& TopElement);
  bool Push(const int& NewElement);
  // Additions
  int getIndex();
  int getElement(int index);
};
#endif
