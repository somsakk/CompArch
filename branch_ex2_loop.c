#include<stdio.h>

int main () {
    int A[] = {8,1024,-2};
    int sum = 0, i = 0;
    int N = 3; // length of array A

    for (i = 0; i < N; i++) {
        sum += A[i];
        printf("i = %d, A[%d] = %d = %#x, ", i, i, A[i], A[i]);
        printf("current sum = %d = %#x\n", sum, sum);
    }
    printf("sum = %d = %#x\n", sum, sum);
}


