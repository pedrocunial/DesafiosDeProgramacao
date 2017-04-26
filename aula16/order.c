#include <stdio.h>
#include <stdlib.h>


void sort(int v[], size_t len)
{
  int *count = (int *) calloc(len, sizeof(int));
  for (int i = 0; i < len; i++) {
    count[v[i]] += 1;
  }
  for (int i = 0; i < 10; i++) {
    printf("%d ", count[i]);
  }
  printf("\n");
  size_t index = 0;
  for (int i = 0; i < len; i++) {
    int n = count[i];
    while (n--) {
      v[index] = i;
      index++;
    }
  }
}

void sort2(int v[], int n)
{
  int nums[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      nums[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    int j = 0;
    while (nums[v[i] % 10][j] != 0) {
      j++;
    }
    nums[(v[i] % 10)][j] = v[n];
  }
  int index = 0;
  for (int i = 0; i < n; i++) {
    int j = 0;
    while (nums[i][j] != 0) {
      v[index] = nums[i][j];
      j++;
      index++;
    }
  }
}

void sort3(int v[], int n)
{
  int *count = (int *) calloc(n, sizeof(int));
  int *count2 = (int *) calloc(n, sizeof(int));
  int vcpy[n];
  for (int i = 0; i < n; i++) {
    vcpy[i] = v[i];
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    count[v[i] % 10] += 1;
  }
  for (int i = 0; i < n; i++) {
    sum += count[i];
    count2[i] = sum;
  }
  for (int i = 0; i < n; i++) {
    int l = vcpy[i] % 10;
    int tmp = count2[l] - count[l];
    v[tmp] = vcpy[i];
    count[l]--;
  }
  printf("\n");
}

int main(void)
{
  int vec[] = {3, 2, 1, 4, 3, 2, 1, 8, 7, 0};
  sort(vec, 10);

  for (int i = 0; i < 10; i++) {
    printf("%d ", vec[i]);
  }
  printf("\n");

  int v2[] = {
    321,
    123,
    234,
    432,
    345,
    543,
    456,
    654,
    567,
    990
  };
  sort3(v2, 10);

  for (int i = 0; i < 10; i++) {
    printf("%d ", v2[i]);
  }
  printf("\n");
  return 0;
}
