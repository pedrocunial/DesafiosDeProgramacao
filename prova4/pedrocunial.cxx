#include <iostream>

#define SIZE 7


struct treco_t {
  int key;
};

template<typename T>
class Tabela {
private:
  struct node_t {
    T *value;
    node_t *next;
  };
  node_t *table[7];

public:
  Tabela();
  ~Tabela();
  T *find(int key);
  void add(int key);
  void remove(int key);
  void print();
};

template<typename T>
Tabela<T>::Tabela(){
  for (int i = 0; i < SIZE; i++) {
    table[i] = NULL;
  }
}

template<typename T>
Tabela<T>::~Tabela()
{
  for (int i = 0; i < SIZE; i++) {
    node_t *next = NULL;
    node_t *curr = table[i];
    while (curr != NULL) {
      next = curr->next;
      delete curr->value;
      delete curr;
      curr = next;
    }
  }
}

template<typename T>
T *Tabela<T>::find(int key)
{
  int hash = key % SIZE;
  node_t *node = table[hash];
  while (node != NULL) {
    if (node->value->key == key)
      return node->value;
    node = node->next;
  }
  return NULL;
}

template<typename T>
void Tabela<T>::add(int key)
{
  int hash = key % SIZE;
  node_t *node = table[hash];
  node_t *prev = NULL;
  while (node != NULL) {
    prev = node;
    node = node->next;
  }

  T *value = new T;
  value->key = key;

  if (prev == NULL) {
    // primeiro adicionado
    table[hash] = new node_t;
    table[hash]->value = value;
    table[hash]->next = NULL;
  } else {
    node = new node_t;
    prev->next = node;
    node->value = value;
    node->next = NULL;
  }
}

template<typename T>
void Tabela<T>::remove(int key)
{
  int hash = key % SIZE;
  node_t *curr = table[hash];
  node_t *prev = NULL;

  while (curr != NULL) {
    if (curr->value->key == key)
      break;
    prev = curr;
    curr = curr->next;
  }

  if (curr == NULL)
    return;

  if (prev != NULL)
    prev->next = curr->next;
  else
    table[hash] = curr->next;

  delete curr;
}

template<typename T>
void Tabela<T>::print()
{
  for (node_t *node : table) {
    while (node != NULL) {
      std::cout << node->value->key << " ";
      node = node->next;
    }
    std::cout << std::endl;
  }
}

int main()
{
  Tabela<treco_t> *tabela = new Tabela<treco_t>();


  std::cout << "Adicionando:" << std::endl;
  tabela->add(3);
  tabela->add(21);
  tabela->add(0);
  tabela->add(7);
  tabela->print();

  std::cout << "Removendo:" << std::endl;
  tabela->remove(7);
  tabela->remove(21);
  tabela->print();

  std::cout << "Encontrando:" << std::endl;
  treco_t *treco = tabela->find(3);
  std::cout << treco->key << std::endl;
  treco = tabela->find(0);
  std::cout << treco->key << std::endl;

  delete tabela;
  return 0;
}
