#include "deque.hxx"

template <typename T>
Deque<T>::Deque()
{
  beg = 0;
  end = 0;
}

template <typename T>
Deque<T>::~Deque()
{
  // delete[] arr;
}

template <typename T>
void Deque<T>::sub_index(int *id)
{
  *id = *id > 0 ? *id - 1 : SIZE - 1;
}

template <typename T>
T Deque<T>::pop_back()
{
  sub_index(&end);
  return arr[end % SIZE];
}

template <typename T>
T Deque<T>::pop_front()
{
  T value = arr[beg % SIZE];
  beg++;
  return value;
}

template <typename T>
void Deque<T>::push_back(T value)
{
  arr[end % SIZE] = value;
  end++;
}

template <typename T>
void Deque<T>::push_front(T value)
{
  sub_index(&beg);
  arr[beg % SIZE] = value;
}

template <typename T>
bool Deque<T>::empty()
{
  return beg == end;
}
