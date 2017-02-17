#ifndef QUEUE_H
#define QUEUE_H

// Standard queue template with additions

template <class Type>
class queue
{
private:
  Type *Contents;
  int QueueSize;
  int Front, Back;
public:
  queue(int queuesize = 10);
  ~queue();
  bool Empty() const;
  bool Full() const;
  bool Remove(Type& FrontElement);
  bool Add(const Type& NewElement);
  int getLength();
  bool findQueueMember(const Type member, int& position);
};
#endif
