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


/* int main(void) */
/* { */
/*   charstack *cs = charstack_new(); */
/*   charstack_push(cs, '\n'); */
/*   charstack_push(cs, 'H'); */
/*   charstack_push(cs, 'e'); */
/*   charstack_push(cs, 'l'); */
/*   charstack_push(cs, 'l'); */
/*   charstack_push(cs, 'o'); */
/*   charstack_push(cs, ' '); */
/*   charstack_push(cs, 'W'); */
/*   charstack_push(cs, 'o'); */
/*   charstack_push(cs, 'r'); */
/*   charstack_push(cs, 'l'); */
/*   charstack_push(cs, 'd'); */
/*   charstack_push(cs, '!'); */

/*   while (cs->sp) { */
/*     printf("%c", charstack_pop(cs)); */
/*   } */
/*   return 0; */
/* } */
