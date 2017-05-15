#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


template<typename T>
class MultiSet {
private:
  struct node {
    node *next;
    T value;
  };
  node *head;
  void rm_node(node *prev, node *curr);

public:
  MultiSet();
  ~MultiSet();
  bool empty();
  int how_many(T value);
  void add(T value);
  void remove(T value);
  void print();
};

template<typename T>
MultiSet<T>::MultiSet()
{
  head = NULL;
}

template<typename T>
MultiSet<T>::~MultiSet()
{
  node *curr = head;
  node *tmp;
  while (curr != NULL) {
    tmp = curr;
    curr = curr->next;
    delete tmp;
  }
}

template<typename T>
bool MultiSet<T>::empty()
{
  return head == NULL;
}

template<typename T>
int MultiSet<T>::how_many(T value)
{
  int count = 0;
  node *curr = head;
  while (curr != NULL) {
    if (curr->value == value)
      count++;
    curr = curr->next;
  }
  return count;
}

template<typename T>
void MultiSet<T>::add(T value)
{
  node *_node = new node;
  _node->value = value;
  _node->next = head;
  head = _node;
}

template<typename T>
void MultiSet<T>::remove(T value)
{
  node *curr, *prev;
  curr = head;
  prev = NULL;
  while (curr != NULL) {
    if (curr->value == value) {
      rm_node(prev, curr);
      return;
    }
    prev = curr;
    curr = curr->next;
  }
}

template<typename T>
void MultiSet<T>::rm_node(node *prev, node *curr)
{
  if (prev == NULL) {
    // first node, should change the head
    head = curr->next;
  } else {
    prev->next = curr->next;
  }
  delete curr;
}

template<typename T>
void MultiSet<T>::print()
{
  node *curr = head;
  while (curr != NULL) {
    std::cout << curr->value << " ";
    curr = curr->next;
  }
  std::cout << std::endl;
}


int main() {
  std::srand(std::time(NULL));

  MultiSet<int> *s = new MultiSet<int>();

  int r;

  for(int i = 0; i < 10; i++) {
    r = std::rand() % 10;
    std::cout << "tentando adicionar " << r << "\n";
    s->add(r);
    s->print();
  }

  for(int i = 0; i < 10; i++) {
    if(s->empty()) {
      std::cout << "nada a remover\n";
    }
    else {
      r = std::rand() % 10;
      if(s->how_many(r)) {
        std::cout << "removendo " << r << "\n";
        s->remove(r);
      }
      else {
        std::cout << r << " nao existe no conjunto\n";
      }
      s->print();
    }
  }

  delete s;

  return 0;
}
