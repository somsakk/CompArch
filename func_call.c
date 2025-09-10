// func_call.c
#include <stdio.h>

int f2(int n, int m) { // n is a local variable in f2() function
    n = n + 1;
    printf("in f2: n = %d\n", n);
    return n + m; // return the value of n
}

int f1(int n) { // n is a local variable in sum() function
    n = n + 1;
    printf("in f1: n = %d\n", n);
    return f2(n, 2*n);
}

int main(void) {
  int n = 5; // n is a local variable in main() function
  printf("in main: n = %d\n", n);
  printf("f1(n) returns %d\n", f1(n)); // calls f1 function
  printf("in main: n = %d\n", n);
}
