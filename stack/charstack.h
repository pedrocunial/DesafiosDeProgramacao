#ifndef __CHARSTACK_H__
#define __CHARSTACK_H__

#define ARRLEN 100

typedef struct {
  char array[ARRLEN];
  int  sp;
} charstack;

charstack *charstack_new();
void charstack_push(charstack *s, int value);
char charstack_pop(charstack *s);
void charstack_delete(charstack *s);

#endif
