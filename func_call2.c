// func_cal12.c
#include <stdio.h>

#define TEST_NUM 5

// function prototypes
int foo1(int, int);
int foo2(int, int);

int main() {
    int result = foo2(10, 20) + TEST_NUM;
    printf("result = %d\n", result);
    // return result;
    return 0;
}

int foo1(int a, int b) {
    return a*b;
}

int foo2(int a, int b) {
    return a + foo1(b,8) - TEST_NUM;
}

