#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>


void memswp(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(int *vec, size_t n)
{
    n--;
    if (!n) return;
    for (size_t j = 0; j < n; j++) {
        if (vec[j] > vec[j + 1])
            memswp(&vec[j], &vec[j + 1]);
    }
    bubble_sort(vec, n);
}

int index_greatest(int *vec, size_t n)
{
    int id = 0;
    for (size_t i = 1; i < n; i++) {
        if (vec[i] > vec[id]) id = i;
    }
    return id;
}

void selection_sort(int *vec, size_t n)
{
    if (n < 1) return;
    int id = index_greatest(vec, n);
    memswp(&vec[id], &vec[n - 1]);
    selection_sort(vec, n - 1);
}

void insertion_sort(int *vec, size_t n)
{
    if (n < 1) return;
    insertion_sort(vec, n - 1);
    int tmp = vec[n];
    size_t j = n - 1;
    while (j >= 0 && vec[j] > tmp) {
        vec[j + 1] =  vec[j];
        j--;
    }
    vec[j + 1] = tmp;
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
    /* int vec[] = {2, 3, 2, 1, 4, 2}; */
    /* bubble_sort(vec, 6); */
    /* print_array(vec, 6); */

    /* int vec2[] = {2, 3, 2, 1, 4, 2}; */
    /* selection_sort(vec2, 6); */
    /* print_array(vec2, 6); */

    /* int vec3[] = {2, 3, 2, 1, 4, 2}; */
    /* insertion_sort(vec3, 6); */
    /* print_array(vec3, 6); */
    return 0;
}
