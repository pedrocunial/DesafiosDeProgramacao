#include "stack.hxx"

template<typename T>
Stack<T>::Stack()
{
  sp = 0;
}

template<typename T>
Stack<T>::~Stack()
{
  vec.clear();
}

template<typename T>
void Stack<T>::push(T value)
{
  vec.push_back(value);
  sp++;
}

template<typename T>
T Stack<T>::pop()
{
  sp--;
  return vec[sp];
}

template<typename T>
bool Stack<T>::empty()
{
  return sp <= 0;
}
