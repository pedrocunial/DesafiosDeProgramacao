#ifndef __DEQUE_H__
#define __DEQUE_H__

#define SIZE 100

template <typename T>
class Deque {
private:
  T arr[SIZE];
  int end;
  int beg;
  void sub_index(int *id);

public:
  Deque();
  ~Deque();
  T pop_back();
  T pop_front();
  bool empty();
  void push_back(T value);
  void push_front(T value);
};

#include "deque.cxx"

#endif // __DEQUE_H__
