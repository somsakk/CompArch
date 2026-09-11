// pointer_ex1.c
#include <stdio.h>

void foo(int n) {
    printf("in foo: &n = %p\n", &n);
    n = 5;
    return;
}

void foo2(int* nptr) {
    printf("in foo2: nptr = %p, *nptr = %d\n", nptr, *nptr);
    *nptr = 5;
    printf("in foo2: nptr = %p, *nptr = %d\n", nptr, *nptr);
    return;
}

int main() {
    int n = 2;
    printf("in main: &n = %p\n", &n);
    foo(n);
    printf("n = %d\n", n);

    foo2(&n);
    printf("n = %d\n", n);
}