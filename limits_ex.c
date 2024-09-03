// limits_ex.c
#include <stdio.h>
#include <stdlib.h> // This library declares sizeof() function
#include <limits.h> // for limits
#include <stdint.h> // for unint32_t type
// print sizes of various types
void printlimits() {
    printf("1. %d, %d\n", (int) sizeof(int), (int) sizeof(unsigned int));
    printf("2. int min = %d, max = %d\n", INT_MIN, INT_MAX);
    printf("3. int min = %x, max = %x\n", INT_MIN, INT_MAX);
    printf("4. int min = %#x, max = %#x\n", INT_MIN, INT_MAX); // add 0x before the number
    printf("5. unsigned int max = %d\n", UINT_MAX); // print int
    printf("6. unsigned int max = %u\n", UINT_MAX); // print unsigned int
    printf("7. unsigned int max = %#x\n", UINT_MAX);
}
int main() {
    int a=0x7fffffff;    // INT_MAX;
    uint32_t b=0xffffffff; // UINT_MAX
    printlimits();
    printf("8. a = %d = %u = %#x\n", a, a, a);
    printf("8.1 a+1 = %d = %u = %#x\n", a+1, a+1, a+1);
    printf("9. b = %d = %u = %#x\n", b, b, b);
    printf("9.1 b+1 = %d = %u = %#x\n", b+1, b+1, b+1);
}