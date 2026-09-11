// pointer_ex1.c
// Compare functions 
#include <stdio.h>

void foo1(int n) {
    printf("in foo1: &n = %p\n", &n);
    n = 5;
    return;
}

void foo2(int* nptr) {
    printf("in foo2: nptr = %p, *nptr = %d\n", nptr, *nptr);
    *nptr = 5;
    printf("in foo2: *nptr = %d\n", *nptr);
    return;
}

int main() {
    int n = 2;
    printf("in main: &n = %p\n", &n);
    printf("in main: n = %d\n", n);
    foo1(n);
    printf("in main: n = %d\n", n);

    foo2(&n);
    printf("in main: n = %d\n", n);
}