#include <stdio.h>
#include <stdlib.h>


void insertion(int vec[], size_t beg, size_t end)
{
  /* Insertion Sort */
  for (size_t i = beg + 1; i <= end; i++) {
    int tmp = vec[i];
    int j = i - 1;
    while(j >= 0 && vec[j] > tmp) {
      vec[j+1] = vec[j];
      j--;
    }
    vec[j+1] = tmp;
  }
}

void merge_r(int vec[], size_t beg, size_t end)
{
  size_t len = (end - beg) / 2;
  if (!len) return;
  merge_r(vec, beg, end - len);
  merge_r(vec, beg + len, end);
  insertion(vec, beg, end);
}

void merge(int vec[], size_t len)
{
  merge_r(vec, 0, len - 1);
}

void print_array(int *vec, size_t n) {
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
  int vec[] = {3, 2, 1, 4, 2, 4};
  merge(vec, 6);
  print_array(vec, 6);
  return 0;
}
