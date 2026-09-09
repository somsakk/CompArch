// add_buggy.c
#include <stdio.h>

int add(int a, int b) {
    int result = a - b;  // bug: should be +
    return result;
}

int main() {
    int x = 5, y = 3;
    int sum = add(x, y);
    printf("Sum: %d\n", sum);
    return 0;
}