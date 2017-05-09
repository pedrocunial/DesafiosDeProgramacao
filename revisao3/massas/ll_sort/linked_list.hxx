#ifndef __LINKED_LIST_HXX__
#define __LINKED_LIST_HXX__

template<typename T>
struct node_t {
  node_t *next;
  T value;
};

template<typename T>
class LinkedList {
private:
  node_t<T> *front;
  node_t<T> *back;
  std::size_t _size;

public:
  LinkedList();
  ~LinkedList();
  void push_back(T value);
  T get(std::size_t i);
  inline std::size_t size();
  inline node_t<T> * get_head();
  inline node_t<T> * get_tail();
  inline void set_head(node_t<T> *node);
  inline void set_tail(node_t<T> *node);
};

#include "linked_list.cxx"

#endif
