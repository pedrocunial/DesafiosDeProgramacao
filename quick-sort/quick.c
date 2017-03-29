#include <stdio.h>
#include <stdlib.h>


void quick(int vec[], size_t n)
{
  quick_r(vec, 0, n - 1);
}

void print_array(int vec[], size_t n) {
  printf("[");
  for (size_t i = 0; i < n; i++) {
    printf("%d", vec[i]);
    if (i < n - 1)
      printf(", ");
  }
  puts("]");
}

int main(void)
{
  return 0;
}
