#include <stdio.h>
#include <time.h>
#include <sys/times.h>

/* mude a linha abaixo para trocar o limite */
#define MAX 1000

void facil(int n) {
    // n^3
    for(int i = n; i > 0; i--) {
        for(int j = n; j > 0; j--) {
            for(int k = 0; k < j; k++) {
                printf("facil\n");
            }
        }
    }
}

void hanoi(int n, char src, char aux, char dst) {
    // 2^n
    if(n > 1) {
        hanoi(n - 1, src, dst, aux);
    }
    printf("mova %d de %c para %c\n", n, src, dst);
    if(n > 1) {
        hanoi(n - 1, aux, src, dst);
    }
}

void feioso(int n) {
    // log(n)
    for(int i = 1; i < n; i *= 2);
}

void blargh(int n) {
    // n
    if(n < 2) {
        return;
    }
    blargh(n / 2);
    blargh(n / 2);
}

void ma_che(int n) {
    // 2^n
    if(n > 0) {
        for(int i = 0; i < n; i++);
        ma_che(n - 1);
    }
}

void go_horse(int n) {
    // log(n)
    for(int i = n; i > 0; i /= 3);
}

void ss(int n) {
    // n * log(n) * log(n) = n * log^2(n)
    for(int i = n; i > 0; i -= 1) {
        for(int j = n; j > 0; j /= 2) {
            for(int k = 0; k < j; k++) {
                printf("ma oe\n");
            }
        }
    }
}

void noia(int n) {
    // n^2
    int m = 1000 * n;
    for(int i = 0; i < m; i += n) {
        for(int j = 0; j < m; j += n) {
            printf("rawr\n");
        }
    }
}

void beer(int n) {
    // n + 2^n = 2^n
    int m = 1;
    for(int i = n; i > 0; i--) {
        // n
        m *= 2;
    }
    for(int j = 0; j < m; j++) {
        // 2^n
        printf("%d bottles of beer on the wall\n", j);
    }
}

void pas(int n) {
    // n * log(n)
    for(int i = 0; i < n; i += 2) {
        for(int j = 1; j < n; j *= 2) {
            printf("#PAS\n");
        }
    }
}

void eita_p(int n) {
    // n
    int m = n;
    for(int i = n; i > 0; i--) {
        m *= 2;
    }
    for(int j = 0; j < m; j++) {
        m /= 2;
    }
}

void wtf(int n) {
    // n^3
    for(int i = n; i > 0; i -= 1) {
        for(int j = n; j > 0; j -= 2) {
            for(int k = 0; k < j; k++) {
                printf("wtf\n");
            }
        }
    }
}

void insano(int n) {
    // 2*log(n) + n = n + n = n
    if (n == 0) return;
    insano(n / 2);
    for(int i = 0; i < n; i++);
    insano(n / 2);
}

int main(void)
{
    struct tms t;
    clock_t begin, end;
    double elapsed;

    /* fprintf(stderr, "n,tempo\n"); */
    /* for(int n = 1; n <= MAX; n++) { */
    /*     times(&t); */
    /*     begin = t.tms_utime + t.tms_stime; */

    /*     /\* mude a linha abaixo para trocar a funcao *\/ */
    /*     facil(n); */

    /*     times(&t); */
    /*     end = t.tms_utime + t.tms_stime; */

    /*     elapsed = (double) (end - begin) / CLOCKS_PER_SEC; */
    /*     fprintf(stderr, "%d,%lf\n", n, elapsed); */
    /* } */

    /* fprintf(stderr, "n,tempo\n"); */
    /* for(int n = 1; n <= MAX; n++) { */
    /*     times(&t); */
    /*     begin = t.tms_utime + t.tms_stime; */

    /*     /\* mude a linha abaixo para trocar a funcao *\/ */
    /*     hanoi(n, 'a', 'b', 'c'); */

    /*     times(&t); */
    /*     end = t.tms_utime + t.tms_stime; */

    /*     elapsed = (double) (end - begin) / CLOCKS_PER_SEC; */
    /*     fprintf(stderr, "%d,%lf\n", n, elapsed); */
    /* } */

    /* fprintf(stderr, "n,tempo\n"); */
    /* for(int n = 1; n <= MAX; n++) { */
    /*     times(&t); */
    /*     begin = t.tms_utime + t.tms_stime; */

    /*     /\* mude a linha abaixo para trocar a funcao *\/ */
    /*     feioso(n); */

    /*     times(&t); */
    /*     end = t.tms_utime + t.tms_stime; */

    /*     elapsed = (double) (end - begin) / CLOCKS_PER_SEC; */
    /*     fprintf(stderr, "%d,%lf\n", n, elapsed); */
    /* } */

    /* fprintf(stderr, "n,tempo\n"); */
    /* for(int n = 1; n <= MAX; n++) { */
    /*     times(&t); */
    /*     begin = t.tms_utime + t.tms_stime; */

    /*     /\* mude a linha abaixo para trocar a funcao *\/ */
    /*     blargh(n); */

    /*     times(&t); */
    /*     end = t.tms_utime + t.tms_stime; */

    /*     elapsed = (double) (end - begin) / CLOCKS_PER_SEC; */
    /*     fprintf(stderr, "%d,%lf\n", n, elapsed); */
    /* } */

    /* fprintf(stderr, "n,tempo\n"); */
    /* for(int n = 1; n <= MAX; n++) { */
    /*     times(&t); */
    /*     begin = t.tms_utime + t.tms_stime; */

    /*     /\* mude a linha abaixo para trocar a funcao *\/ */
    /*     ma_che(n); */

    /*     times(&t); */
    /*     end = t.tms_utime + t.tms_stime; */

    /*     elapsed = (double) (end - begin) / CLOCKS_PER_SEC; */
    /*     fprintf(stderr, "%d,%lf\n", n, elapsed); */
    /* } */

    /* fprintf(stderr, "n,tempo\n"); */
    /* for(int n = 1; n <= MAX; n++) { */
    /*     times(&t); */
    /*     begin = t.tms_utime + t.tms_stime; */

    /*     /\* mude a linha abaixo para trocar a funcao *\/ */
    /*     go_horse(n); */

    /*     times(&t); */
    /*     end = t.tms_utime + t.tms_stime; */

    /*     elapsed = (double) (end - begin) / CLOCKS_PER_SEC; */
    /*     fprintf(stderr, "%d,%lf\n", n, elapsed); */
    /* } */

    /* fprintf(stderr, "n,tempo\n"); */
    /* for(int n = 1; n <= MAX; n++) { */
    /*     times(&t); */
    /*     begin = t.tms_utime + t.tms_stime; */

    /*     /\* mude a linha abaixo para trocar a funcao *\/ */
    /*     ss(n); */

    /*     times(&t); */
    /*     end = t.tms_utime + t.tms_stime; */

    /*     elapsed = (double) (end - begin) / CLOCKS_PER_SEC; */
    /*     fprintf(stderr, "%d,%lf\n", n, elapsed); */
    /* } */

    /* fprintf(stderr, "n,tempo\n"); */
    /* for(int n = 1; n <= MAX; n++) { */
    /*     times(&t); */
    /*     begin = t.tms_utime + t.tms_stime; */

    /*     /\* mude a linha abaixo para trocar a funcao *\/ */
    /*     noia(n); */

    /*     times(&t); */
    /*     end = t.tms_utime + t.tms_stime; */

    /*     elapsed = (double) (end - begin) / CLOCKS_PER_SEC; */
    /*     fprintf(stderr, "%d,%lf\n", n, elapsed); */
    /* } */

    /* fprintf(stderr, "n,tempo\n"); */
    /* for(int n = 1; n <= MAX; n++) { */
    /*     times(&t); */
    /*     begin = t.tms_utime + t.tms_stime; */

    /*     /\* mude a linha abaixo para trocar a funcao *\/ */
    /*     beer(n); */

    /*     times(&t); */
    /*     end = t.tms_utime + t.tms_stime; */

    /*     elapsed = (double) (end - begin) / CLOCKS_PER_SEC; */
    /*     fprintf(stderr, "%d,%lf\n", n, elapsed); */
    /* } */

    /* fprintf(stderr, "n,tempo\n"); */
    /* for(int n = 1; n <= MAX; n++) { */
    /*     times(&t); */
    /*     begin = t.tms_utime + t.tms_stime; */

    /*     /\* mude a linha abaixo para trocar a funcao *\/ */
    /*     pas(n); */

    /*     times(&t); */
    /*     end = t.tms_utime + t.tms_stime; */

    /*     elapsed = (double) (end - begin) / CLOCKS_PER_SEC; */
    /*     fprintf(stderr, "%d,%lf\n", n, elapsed); */
    /* } */

    /* fprintf(stderr, "n,tempo\n"); */
    /* for(int n = 1; n <= MAX; n++) { */
    /*     times(&t); */
    /*     begin = t.tms_utime + t.tms_stime; */

    /*     /\* mude a linha abaixo para trocar a funcao *\/ */
    /*     eita_p(n); */

    /*     times(&t); */
    /*     end = t.tms_utime + t.tms_stime; */

    /*     elapsed = (double) (end - begin) / CLOCKS_PER_SEC; */
    /*     fprintf(stderr, "%d,%lf\n", n, elapsed); */
    /* } */

    /* fprintf(stderr, "n,tempo\n"); */
    /* for(int n = 1; n <= MAX; n++) { */
    /*     times(&t); */
    /*     begin = t.tms_utime + t.tms_stime; */

    /*     /\* mude a linha abaixo para trocar a funcao *\/ */
    /*     wtf(n); */

    /*     times(&t); */
    /*     end = t.tms_utime + t.tms_stime; */

    /*     elapsed = (double) (end - begin) / CLOCKS_PER_SEC; */
    /*     fprintf(stderr, "%d,%lf\n", n, elapsed); */
    /* } */

    fprintf(stderr, "n,tempo\n");
    for(int n = 1; n <= MAX; n++) {
        times(&t);
        begin = t.tms_utime + t.tms_stime;

        /* mude a linha abaixo para trocar a funcao */
        insano(n);

        times(&t);
        end = t.tms_utime + t.tms_stime;

        elapsed = (double) (end - begin) / CLOCKS_PER_SEC;
        fprintf(stderr, "%d,%lf\n", n, elapsed);
    }

    return 0;
}
