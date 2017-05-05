#include <iostream>
#include <string>
#include <cmath>

#include "lldeque.hxx"

int main() {
  // stack
  std::string line;

  printf("digite uma linha de texto: ");
  std::getline(std::cin, line);

  unsigned int n = line.size();

  Deque<char> *s = new Deque<char>();

  for(unsigned int i = 0; i < n; i++) {
    char c = line[i];

    if(c == '(') {
      s->push_back(')');
    }
    else if(c == '[') {
      s->push_back(']');
    }
    else if(c == '{') {
      s->push_back('}');
    }
    else if(c == ')' || c == ']' || c == '}') {
      if(s->empty() == true) {
        printf("fechamento excessivo\n");
        return 0;
      }
      if(s->pop_back() != c) {
        printf("fechamento invalido\n");
        return 0;
      }
    }
  }

  if(s->empty() == false) {
    printf("abertura excessiva\n");
  }
  else {
    printf("bem formada\n");
  }

  delete s;

  // queue
  n;
  std::cin >> n;

  int max = 4 * (1 - pow(4, n)) / -3;

  Deque<std::string> *q = new Deque<std::string>();
  q->push_back("");

  while(!q->empty()) {
    std::string s = q->pop_front();

    if(s.size() > 0) {
      std::cout << s << "\n";
    }

    if(s.size() < n) {
      q->push_back(s + "A");
      q->push_back(s + "C");
      q->push_back(s + "G");
      q->push_back(s + "T");
    }
  }

  delete q;

  return 0;
}
