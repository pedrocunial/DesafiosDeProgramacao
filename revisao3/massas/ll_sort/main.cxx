#include <iostream>
#include <string>

#include "linked_list.hxx"

#define SPACER "====================="


using namespace std;

void merge_sort(LinkedList<int> *list);  // 1
void merge_sort_r(node_t<int> *head, node_t<int> *tail);  // aux for 1
void node_join(node_t<int> *a, node_t<int> *b);
void reverse(LinkedList<int> *list);  // 2
node_t<int> *middle_node(LinkedList<int> *list);  // 3
node_t<int> *middle_node_simplified(node_t<int> *head);
bool palindrom(LinkedList<char> *list);  // 4
void join(LinkedList<int> *first, LinkedList<int> *sec);

inline void print_spacer() { cout << SPACER << endl; }

void reverse(LinkedList<int> *list)
{
  node_t<int> *head = list->get_head();
  node_t<int> *prev = NULL;
  node_t<int> *tmp;
  for (tmp = head; tmp != NULL; tmp = head) {
    head = tmp->next;
    tmp->next = prev;
    prev = tmp;
  }
  head = list->get_head();
  list->set_head(prev);
  list->set_tail(head);
}

bool palindrom(LinkedList<int> *list)
{
  LinkedList<int> *rev = new LinkedList<int>();
  node_t<int> *head = list->get_head();
  while (head != NULL) {
    rev->push_back(head->value);
    head = head->next;
  }
  reverse(rev);
  node_t<int> *rev_node = rev->get_head();
  node_t<int> *ori_node = list->get_head();
  while (ori_node != NULL) {
    if (rev_node->value != ori_node->value)
      return false;
    rev_node = rev_node->next;
    ori_node = ori_node->next;
  }
  delete rev;
  return true;
}

node_t<int> *middle_node_simplified(node_t<int> *head)
{
  node_t<int> *curr = head;
  node_t<int> *mid  = NULL;
  bool         flip = false;
  while (curr != NULL) {
    curr = curr->next;
    if (flip) {
      if (mid == NULL)
        mid = head;
      else
        mid = mid->next;
      flip = false;
    } else {
      flip = true;
    }
  }
  return mid;
}

node_t<int> *middle_node(LinkedList<int> *list)
{
  return middle_node_simplified(list->get_head());
}

void node_join(node_t<int> *a, node_t<int> *b)
{
  // base cases
  if (a == NULL) {
    a = b;
    return;
  }
  if (b == NULL) return;

  node_t<int> *head;
  node_t<int> *curr;
  if (a->value < b->value) {
    head = a;
    a = a->next;
  } else {
    head = b;
    b = b->next;
  }
  while ((a != NULL) || (b != NULL)) {
    if (a == NULL)
      curr->next = b;
    else if (b == NULL)
      curr->next = a;
    else if (a->value > b->value)
      curr->next = b;
    else
      curr->next = a;
    curr = curr->next;
  }
  a = head;
}

void merge_sort_r(node_t<int> *head, node_t<int> *tail)
{
  cout << head->value << " " << tail->value << endl;
  node_t<int> *a, *b;
  if ((head == NULL) || (head->next == NULL))
    // base
    return;
  a = middle_node_simplified(head);
  if ((a == head) || (a == NULL)) return;
  b = a->next;
  if ((b == tail) || (b == NULL)) return;
  a->next = NULL;
  merge_sort_r(head, a);
  merge_sort_r(b, tail);
  node_join(head, b);
}

void merge_sort(LinkedList<int> *list)
{
  node_t<int> *head = list->get_head();
  node_t<int> *tail = list->get_tail();
  merge_sort_r(head, tail);
  list->set_head(head);
  list->set_tail(tail);
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

  print_spacer();
  node_t<int> *head = list->get_head();
  cout << "Original List" << endl;
  while (head != NULL) {
    cout << head->value << " ";
    head = head->next;
  }
  cout << endl;
  print_spacer();

  // Reverse
  reverse(list);
  head = list->get_head();
  cout << "Reversed List" << endl;
  while (head != NULL) {
    cout << head->value << " ";
    head = head->next;
  }
  cout << endl;
  print_spacer();

  // Middle Node
  node_t<int> *mid = middle_node(list);
  cout << "Middle Node" << endl;
  cout << mid->value << endl;
  print_spacer();

  // Palindrome
  cout << "Is Palindrome" << endl;
  cout << (palindrom(list) ? "True" : "False") << endl;
  print_spacer();

  // Sort
  cout << "Sort O(n log(n))" << endl;
  merge_sort(list);
  head = list->get_head();
  while (head != NULL) {
    cout << head->value << " ";
    head = head->next;
  }
  cout << endl;
  print_spacer();

  // Join
  LinkedList<int> *list2 = new LinkedList<int>();
  list2->push_back(3);
  list2->push_back(0);
  list2->push_back(1);
  list2->push_back(-2);
  list2->push_back(9);
  list2->push_back(4);
  list2->push_back(2);
  list2->push_back(-3);
  list2->push_back(0);

  delete list;
  delete list2;

  return 0;
}
