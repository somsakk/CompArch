// types2.c

#include <stdio.h>
// #include <stdlib.h>
#include <stdint.h> // เพื่อ sizeof() และ int8_t, uint8_t, int16_t, ...

int main() {
    printf("\nInteger type\tbytes\n");
    printf("char\t\t%d\n", (int) sizeof(char));
    printf("int\t\t%d\n", (int) sizeof(int));
    printf("unsigned int\t%d\n", (int) sizeof(unsigned int));
    printf("short\t\t%d\n", (int) sizeof(short));
    printf("long\t\t%d\n", (int) sizeof(long));
    printf("long long\t%d\n", (int) sizeof(long long));
    printf("int8_t\t\t%d\n", (int) sizeof(int8_t));
    printf("int16_t\t\t%d\n", (int) sizeof(int16_t));
    printf("int32_t\t\t%d\n", (int) sizeof(int32_t));
    printf("int64_t\t\t%d\n", (int) sizeof(int64_t));

    printf("\nFloating type\tbytes\n");
    printf("float\t\t%d\n", (int) sizeof(float));
    printf("double\t\t%d\n", (int) sizeof(double));
    printf("long double\t%d\n\n", (int) sizeof(long double));

    int a=0xffff, d=-1;
    int ar[3] = {1, 2, 3};
    float b=0.25;
    char c = 127, f = c+1;
    printf("size of a: %d, size of d: %d, size of ar: %d, size of b: %d, size of c: %d\n", (int) sizeof(a), (int) sizeof(d), (int) sizeof(ar), (int) sizeof(b), (int) sizeof(c));
    // print values of variables in decimal format
    printf("a: %d, d: %d, ar: %d, b: %f, c: %c\n", a, d, ar[0], b, c);
    // print variables in hexadecimal format. Notice that we need to cast float b to int pointer and dereference it to print its hexadecimal representation.
    printf("a: %#x, d: %#x, ar[0]: %#x, b: %#x, c: %#x\n", a, d, ar[0] , *(int*)&b, c);
    printf("f: in hex %#x, value in decimal %d\n", f, f);
}