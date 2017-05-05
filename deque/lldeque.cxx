#include "lldeque.hxx"

template<typename T>
Deque<T>::Deque()
{
  front = NULL;
  back  = NULL;
}

template<typename T>
Deque<T>::~Deque()
{
  while (front != back) {
    node_t *tmp = front;
    front = front->next;
    delete tmp;
  }
  if (back != NULL)
    delete back;
  delete front;
}

template<typename T>
T Deque<T>::pop_back()
{
  T value = back->value;
  node_t *tmp = back;
  back = back->prev;
  back->next = NULL;
  delete tmp;
  return value;
}

template<typename T>
T Deque<T>::pop_front()
{
  T value = front->value;
  node_t *tmp = front;
  front = front->next;
  front->prev = NULL;
  delete tmp;
  return value;
}

template<typename T>
bool Deque<T>::empty()
{
  return (front == NULL) && (back == NULL);
}

template<typename T>
void Deque<T>::push_back(T value)
{
  node_t *tmp = new node_t;
  tmp->next = NULL;
  tmp->prev = back;
  tmp->value = value;
  back->next = tmp;
  back = tmp;
}

template<typename T>
void Deque<T>::push_front(T value)
{
  node_t *tmp = new node_t;
  tmp->next = front;
  tmp->prev = NULL;
  tmp->value = value;
  front->prev = tmp;
  front = tmp;
}
