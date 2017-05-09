#include <iostream>
#include <string>

#include "linked_list.hxx"

#define SPACER "================"


using namespace std;

void merge_sort(LinkedList<int> *list);  // 1
void reverse(LinkedList<int> *list);  // 2
node_t<int> * middle_node(LinkedList<int> *list);  // 3
bool palindrom(LinkedList<char> *list);  // 4
void join(LinkedList<int> *first, LinkedList<int> *sec);

inline void print_spacer() { cout << SPACER << endl; }

void reverse(LinkedList<int> *list)
{
  node_t<int> *head = list->get_head();
  node_t<int> *tail = list->get_tail();
  node_t<int> *prev = NULL;
  node_t<int> *tmp;
  for (tmp = head; tmp != tail; tmp = head) {
    head = tmp->next;
    tmp->next = prev;
    prev = tmp;
  }
  tmp->next = NULL;
  head = list->get_head();
  list->set_tail(head);
  list->set_head(tail);
}

int main()
{
  LinkedList<int> *list = new LinkedList<int>();
  list->push_back(5);
  list->push_back(8);
  list->push_back(2);
  list->push_back(0);
  list->push_back(-1);
  list->push_back(-1);
  list->push_back(-9);
  list->push_back(-3);

  node_t<int> *head = list->get_head();
  node_t<int> *tail = list->get_tail();
  cout << "Original List" << endl;
  while (head != tail) {
    cout << head->value << " ";
    head = head->next;
  }
  cout << endl;
  print_spacer();

  // Reverse
  reverse(list);
  head = list->get_head();
  tail = list->get_tail();
  cout << "Reversed List" << endl;
  while (head != tail) {
    cout << head->value << " ";
    head = head->next;
  }
  cout << endl;
  print_spacer();

  delete list;

  return 0;
}
