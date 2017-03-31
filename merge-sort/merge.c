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

void merge_r(int vec[], int beg, int end)
{
  size_t i, j, ilim, id, lim, len;
  int *veccpy;
  ilim = end - beg;
  len = ilim / 2;
  j = len + 1;
  printf("%lu %lu\n", beg, end);
  if (beg <= end) return;
  merge_r(vec, beg, len);
  merge_r(vec, j, end);

  /* Merge */
  i = beg;
  veccpy = malloc((ilim + 1) * (sizeof(int)));
  for (id = 0; id < lim; id++) {
    if (i > ilim) {
      veccpy[id] = vec[j];
      j++;
    } else if (j > end) {
      veccpy[id] = vec[i];
      i++;
    } else {
      if (vec[i] < vec[j]) {
        veccpy[id] = vec[i];
        i++;
      } else {
        veccpy[id] = vec[j];
        j++;
      }
    }
  }
  for (i = 0; i < lim; i++) {
    vec[i] = veccpy[i];
  }
}

void merge(int vec[], size_t len)
{
  merge_r(vec, 0, len - 1);
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
  int vec[] = {3, 2, 1, 4, 2, 4};
  merge(vec, 6);
  print_array(vec, 6);
  return 0;
}
