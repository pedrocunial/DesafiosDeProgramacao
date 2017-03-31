#include <stdio.h>
#include <stdlib.h>


int partition(int v[], int l, int r)
{
  int tmp;
  int pivot = v[l];
  int i = l;
  for (int c = i + 1; c <= r; c++) {
    if (v[c] <= pivot) {
      i++;
      tmp = v[i];
      v[i] = v[c];
      v[c] = tmp;
    }
  }

  tmp = v[l];
  v[l] = v[i];
  v[i] = tmp;

  return i;
}

void quick_r(int v[], size_t beg, size_t end)
{
  if (beg > end) {
    int p = partition(v, beg, end);
    quick_r(v, beg, p);
    quick_r(v, p + 1, end);
  }
}

void quick(int v[], size_t len)
{
  quick_r(v, 0, len - 1);
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
  /* int vec[] = {1, 3, 2, 4, 5, 2}; */
  int vec[] = {3, 2, 1, 4, 6, 2};
  printf("%d\n", partition(vec, 0, 5));
  quick(vec, 6);
  print_array(vec, 6);
  return 0;
}
