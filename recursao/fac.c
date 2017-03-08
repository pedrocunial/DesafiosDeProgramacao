#include <stdio.h>


int fatorial(int n)
{
    if (n < 2)
        return 1;
    return n * fatorial(n - 1);
}

int potencia(int b, int e)
{
    if (e == 1)
        return b;
    return b * potencia(b, e - 1);
}

int soma(int *vec, size_t n)
{
    n--;
    if (!n) return vec[n];
    return vec[n] + soma(vec, n);
}

int main(void)
{
    printf("Fatorial de 6: %d\n", fatorial(6));
    printf("2 ^ 10 = %d\n", potencia(2, 10));

    int vec[] = {1, 2, 3, 4};
    printf("Soma do vetor: %d\n", soma(vec, 4));
    return 0;
}
