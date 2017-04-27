#ifndef __CHARSTACK_HXX__
#define __CHARSTACK_HXX__

#include <vector>

class CharStack {
private:
  int sp;
  std::vector<char> vec;

public:
  CharStack();
  void push(char value);
  char pop();
  ~CharStack();
};

#endif
