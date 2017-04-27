#include "charstack.hxx"


CharStack::CharStack()
{
  sp = 1;
}

CharStack::~CharStack()
{
  vec.clear();
}

void CharStack::push(char value)
{
  vec.push_back(value);
  sp++;
}

char CharStack::pop()
{
  sp--;
  return vec[sp];
}

bool CharStack::empty()
{
  return sp <= 1;
}
