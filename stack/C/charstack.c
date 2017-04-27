#include <stdlib.h>
#include <stdio.h>

#include "charstack.h"

charstack *charstack_new() {
  charstack *s = (charstack *) calloc(ARRLEN, sizeof(charstack));
  s->sp = 1;
  return s;
}

void charstack_push(charstack *s, int value) {
  s->array[(s->sp)++] = value;
}

char charstack_pop(charstack *s) {
  return s->array[--(s->sp)];
}

void charstack_delete(charstack *s) {
  free(s);
}
