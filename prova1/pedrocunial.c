#include <stdio.h>


int iter = 0;

void wtf_hanoi(size_t n, char a, char b, char c)
{
  if (n > 0) wtf_hanoi(n - 1, b, c, a);
  iter++;
  printf("All work no play makes Pedro a dull boy\n");
  if (n > 0) {
    wtf_hanoi(n - 1, c, a, b);
    wtf_hanoi(n - 1, a, b, c);
  }
}


int main(void)
{
  iter = 0;
  wtf_hanoi(1, 'a', 'b', 'c');
  printf("Numero de iteracoes: %d\n", iter);
  iter = 0;
  wtf_hanoi(2, 'a', 'b', 'c');
  printf("Numero de iteracoes: %d\n", iter);
  iter = 0;
  wtf_hanoi(3, 'a', 'b', 'c');
  printf("Numero de iteracoes: %d\n", iter);
  return 0;
}
