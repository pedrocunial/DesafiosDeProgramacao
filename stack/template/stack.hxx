#ifndef __STACK_HXX__
#define __STACK_HXX__

#include <vector>

template<typename T>
class Stack {
private:
  int sp;
  std::vector<T> vec;

public:
  Stack();
  void push(T value);
  T pop();
  bool empty();
  ~Stack();
};

#include "stack.cxx"

#endif
