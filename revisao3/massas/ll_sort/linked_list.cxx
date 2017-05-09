#include "linked_list.hxx"

template<typename T>
LinkedList<T>::LinkedList()
{
  front = NULL;
  back  = NULL;
  _size  = 0;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
  while (front != back) {
    node_t<T> *tmp = front;
    front = front->next;
    delete tmp;
  }
  delete front;
}

template<typename T>
void LinkedList<T>::push_back(T value)
{
  node_t<T> *tmp = new node_t<T>;
  tmp->value = value;
  tmp->next = NULL;
  if (_size == 0)
    front = tmp;
  else
    back->next = tmp;
  back = tmp;
  _size++;
}

template<typename T>
T LinkedList<T>::get(std::size_t i)
{
  if (i >= _size) return 0;  // error
  node_t<T> *tmp = front;
  while (i--) {
    tmp = tmp->next;
  }
  return tmp->value;
}

template<typename T>
inline std::size_t LinkedList<T>::size()
{
  return _size;
}

template<typename T>
inline node_t<T> * LinkedList<T>::get_head()
{
  return front;
}

template<typename T>
inline node_t<T> * LinkedList<T>::get_tail()
{
  return back;
}

template<typename T>
inline void LinkedList<T>::set_head(node_t<T> *node)
{
  front = node;
}

template<typename T>
inline void LinkedList<T>::set_tail(node_t<T> *node)
{
  back = node;
}
