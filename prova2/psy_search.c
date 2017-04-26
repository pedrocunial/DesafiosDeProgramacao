#include <stdio.h>
#include <stdlib.h>

#define LEN 8


int psy(int vec[], int len, int val)
{
    int beg = 0, mid = len / 2, end = len - 1, cid0, cid1;
    while (beg <= mid && mid <= end) {
        cid0 = (beg + mid) / 2;
        cid1 = (mid + end) / 2;
        if (vec[cid0] == val)
            return cid0;
        if (vec[cid1] == val)
            return cid1;
        if (val < vec[cid0] && val < vec[cid1])
            mid = cid0 - 1;
        else if (val > vec[cid0] && val > vec[cid1])
            mid = cid1 + 1;
        else if (val > vec[cid0] && val < vec[cid1]) {
            beg += mid / 2;
            end -= mid / 2;
        }
    }
    return -1:;
}

int main(void)
{
    int vec[] = {0, 1, 2, 3, 4, 5, 6, 7};
    printf("O valor %d está no índice %d\n", 7, psy(vec, LEN, 7));
    printf("O valor %d está no índice %d\n", 3, psy(vec, LEN, 3));
    printf("O valor %d está no índice %d\n", 8, psy(vec, LEN, 8));
    printf("O valor %d está no índice %d\n", 4, psy(vec, LEN, 4));
    printf("O valor %d está no índice %d\n", 2, psy(vec, LEN, 2));
    printf("O valor %d está no índice %d\n", 0, psy(vec, LEN, 0));
    return 0;
}
