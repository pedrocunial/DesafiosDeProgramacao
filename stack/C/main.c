#include <stdio.h>
#include <stdlib.h>

#include "charstack.h"


const char *GOOD_STR = "Eu (Pedro) gosto (sério [mesmo]) de pudim {rsrsrs}";
const char *BAD_STR = "Eu Pedro) gosto (sério [mesmo) de pudim {rsrsrs}";
const char *VALID = "valid";
const char *INVALID = "invalid";

char valid(const char *str)
{
  int parc = 0, sqrc = 0, curc = 0;
  charstack *cs = charstack_new();
  while (*str != '\0') {
    charstack_push(cs, *str);
    str++;
  }
  while (cs->sp != 1) {
    char c = charstack_pop(cs);
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
  return !(parc || curc || sqrc);
}

int main(void)
{
  printf("The first string is %s\n", valid(GOOD_STR) ? VALID : INVALID);
  printf("The second string is %s\n", valid(BAD_STR) ? VALID : INVALID);
  return 0;
}
