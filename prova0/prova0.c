#include <stdio.h>
#include <stdlib.h>


size_t find_smallest(int *v, size_t i, size_t n)
{
    int id = i;
    for (i++; i < n; i++) {
        if (v[i] < v[id]) id = i;
    }
    return id;
}

size_t find_biggest(int *v, size_t i, size_t n)
{
    int id = i;
    for (i++; i < n; i++) {
        if (v[i] > v[id]) id = i;
    }
    return id;
}

void memswp(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(int *v, size_t n)
{
    for (size_t i = 0; i < n / 2; i++) {
        memswp(&v[i], &v[find_smallest(v, i, n - i)]);
        memswp(&v[n - 1 - i], &v[find_biggest(v, i, n - i)]);
    }
}

void sort_r_aux(int *v, size_t n, size_t on)
{
    if (n <= on / 2) return;
    int i = on - n;
    memswp(&v[i], &v[find_smallest(v, i, n - i)]);
    memswp(&v[n - 1 - i], &v[find_biggest(v, i, n - i)]);
    sort_r_aux(v, n - 1, on);
}

void sort_r(int *v, size_t n)
{
    sort_r_aux(v, n, n);
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
    puts("SORT ITERATIVO:");
    int arr[] = {1, 3, 2, 5, 4, 2};
    sort(arr, 6);
    print_array(arr, 6);

    puts("SORT RECURSIVO:");
    int arr1[] = {1, 3, 2, 5, 4, 2};
    sort_r(arr1, 6);
    print_array(arr1, 6);
    return 0;
}
