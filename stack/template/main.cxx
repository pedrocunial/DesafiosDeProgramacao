#include <iostream>

#include "stack.hxx"

const char *GOOD_STR = "Eu (Pedro) gosto (sério [mesmo]) de pudim {rsrsrs}";
const char *BAD_STR = "Eu Pedro) gosto (sério [mesmo) de pudim {rsrsrs}";
const char *VALID = "valid";
const char *INVALID = "invalid";

bool valid(const char* str)
{
  int parc = 0, sqrc = 0, curc = 0;
  Stack<char> *cs = new Stack<char>();
  while (*str != '\0') {
    cs->push(*str);
    str++;
  }
  while (!cs->empty()) {
    char c = cs->pop();
    switch (c) {
    case '(':
      parc++;
      break;
    case ')':
      parc--;
      break;
    case '[':
      sqrc++;
      break;
    case ']':
      sqrc--;
      break;
    case '{':
      curc++;
      break;
    case '}':
      curc--;
      break;
    }
  }
  delete cs;
  return !(parc || curc || sqrc);
}

int main()
{
  std::cout << "The first string is " << (valid(GOOD_STR) ? VALID : INVALID) << std::endl;
  std::cout << "The second string is " << (valid(BAD_STR) ? VALID : INVALID) << std::endl;
  return 0;
}
