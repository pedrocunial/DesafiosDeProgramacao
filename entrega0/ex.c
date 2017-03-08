#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 500
#define SAMPLE_SIZE 6
#define N_VEC 100
#define N 1000

int ex0(int *vec, size_t n)
{
    for (size_t i = 0; i < n - 1; i++) {
        if (vec[i] > vec[i+1]) return 0;
    }
    return 1;
}

void ex1(int *vec, size_t n)
{
    for (size_t i = 0; i < n; i++) {
        vec[i] = rand() % MAX;
    }
}

void memswap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void ex2(int *vec, size_t n)
{
    /* Bubble Sort */
    for (size_t i = n - 1; i > 0; i--) {
        int sorted = 1;
        for (size_t j = 0; j < i; j++) {
            if (vec[j] > vec[j + 1]) {
                memswap(&vec[j], &vec[j+1]);
                sorted = 0;
            }
        }
        if (sorted) return;
    }
}

int index_greatest(int *vec, size_t n)
{
    int ans = 0;
    for (size_t i = 1; i < n; i++) {
        if (vec[i] > vec[ans]) ans = i;
    }
    return ans;
}

void ex3(int *vec, size_t n)
{
    /* Selection Sort */
    for (size_t i = n; i > 1; i--) {
        int id = index_greatest(vec, i);
        memswap(&vec[id], &vec[i-1]);
    }
}

void ex4(int *vec, size_t n)
{
    /* Insertion Sort */
    for (size_t i = 1; i < n; i++) {
        int tmp = vec[i];
        int j = i - 1;
        while(j >= 0 && vec[j] > tmp) {
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = tmp;
    }
}

void print_array(int *vec, size_t n)
{
    for (size_t i = 0; i < n; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

void ex5()
{
    int vec_a[N_VEC][N];
    int vec_b[N_VEC][N];
    int vec_c[N_VEC][N];
    for (size_t i = 0; i < N_VEC; i++) {
        ex1(vec_a[i], N);
    }
    memcpy(vec_b, vec_a, N * N_VEC * sizeof(int));
    memcpy(vec_c, vec_a, N * N_VEC * sizeof(int));

    /* Bubble Sort */
    puts("Bubble Sort Failures:");
    for (size_t i = 0; i < N_VEC; i++) {
        ex2(vec_a[i], N);
        if (!ex0(vec_a[i], N)) {
            puts("FAILURE!");
            print_array(vec_a[i], N);
        }
    }
    printf("=============================\n");

    /* Selection Sort */
    puts("Selection Sort Failures:");
    for (size_t i = 0; i < N_VEC; i++) {
        ex3(vec_b[i], N);
        if (!ex0(vec_b[i], N)) {
            puts("FAILURE!");
            print_array(vec_b[i], N);
        }
    }
    printf("=============================\n");

    /* Insertion Sort */
    puts("Insertion Sort Failures:");
    for (size_t i = 0; i < N_VEC; i++) {
        ex4(vec_c[i], N);
        if (!ex0(vec_c[i], N)) {
            puts("FAILURE!");
            print_array(vec_c[i], N);
        }
    }
    printf("=============================\n");
}

int main(void)
{
    srand(time(NULL));

    /* ex 0 */
    int vec_a0[] = {0, 2, 3, 1, 4, 3};
    int vec_a1[] = {0, 1, 2, 3, 4, 5};
    printf("O primeiro vec é ordenado? %d\n", ex0(vec_a0, SAMPLE_SIZE));
    printf("O segundo vec é ordenado? %d\n", ex0(vec_a1, SAMPLE_SIZE));
    printf("=============================\n");

    /* ex 1 */
    int vec_b[SAMPLE_SIZE];
    ex1(vec_b, SAMPLE_SIZE);
    puts("O vetor aleatório gerado foi:");
    print_array(vec_b, SAMPLE_SIZE);
    printf("=============================\n");

    /* ex 2
       Otimizei o código do Bubble Sort ao adicionar uma booleana
       que indica se o array está ou não ordenado. Caso ao iterar
       o array esta booleana não seja alterada, podemos afirmar que
       o array está ordenado e, portanto, não precisamos mais
       iterá-lo.
     */
    ex2(vec_a0, SAMPLE_SIZE);
    puts("Bubble Sorted array:");
    print_array(vec_a0, SAMPLE_SIZE);
    printf("=============================\n");

    /* ex 3 */
    int vec_c[] = {1, 3, 2, 4, 6, 3};
    ex3(vec_c, SAMPLE_SIZE);
    puts("Selection Sorted array:");
    print_array(vec_c, SAMPLE_SIZE);
    printf("=============================\n");

    /* ex 4 */
    int vec_d[] = {1, 3, 2, 4, 6, 3};
    ex4(vec_d, SAMPLE_SIZE);
    puts("Insertion Sorted array:");
    print_array(vec_d, SAMPLE_SIZE);
    printf("=============================\n");

    /* ex 5 */
    puts("\nEXERCÍCIO 5:\n");
    ex5();

    return 0;
}
