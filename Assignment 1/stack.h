#ifndef STACK_H
#define STACK_H

// Variable sized integer stack, using arrays.

class stack
{
private:
  int *Contents;
  int StackSize;
  int IndexOfTop;
public:
  stack(int stacksize = 10);
  ~stack();
  bool Empty() const;
  bool Full() const;
  bool Pop(int& TopElement);
  bool Push(const int& NewElement);
};
#endif
