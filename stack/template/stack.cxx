#include "stack.hxx"

template<class T>
Stack<T>::Stack()
{
  sp = 1;
}

template<class T>
Stack<T>::~Stack()
{
  vec.clear();
}

template<class T>
void Stack<T>::push(T value)
{
  vec.push_back(value);
  sp++;
}

template<class T>
T Stack<T>::pop()
{
  sp--;
  return vec[sp];
}

template<class T>
bool Stack<T>::empty()
{
  return sp <= 1;
}
