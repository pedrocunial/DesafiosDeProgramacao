#ifndef __LLDEQUE_H__
#define __LLDEQUE_H__

template<typename T>
class Deque {
private:
  struct node_t {
    node_t *next;
    node_t *prev;
    T value;
  };
  node_t *front;
  node_t *back;

public:
  Deque();
  ~Deque();
  T pop_back();
  T pop_front();
  bool empty();
  void push_back(T value);
  void push_front(T value);
};

#include "lldeque.cxx"

#endif
