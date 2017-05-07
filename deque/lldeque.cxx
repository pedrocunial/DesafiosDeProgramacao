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
  delete front;
}

template<typename T>
T Deque<T>::pop_back()
{
  if (back == NULL) return 0;
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
  if (front == NULL) return 0;
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
  if (back != NULL) {
    tmp->prev = back;
    back->next = tmp;
  } else if (front != NULL) {
    tmp->prev = front;
    front->next = tmp;
  } else {
    tmp->prev = NULL;
  }
  tmp->value = value;
  back = tmp;
  if (front == NULL)
    front = back;
}

template<typename T>
void Deque<T>::push_front(T value)
{
  node_t *tmp = new node_t;
  tmp->prev = NULL;
  if (front != NULL) {
    tmp->next = front;
    front->prev = tmp;
  } else if (back != NULL) {
    tmp->next = back;
    back->prev = tmp;
  } else {
    tmp->next = NULL;
  }
  tmp->value = value;
  front = tmp;
  if (back == NULL)
    back = front;
}
