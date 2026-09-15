// addone.c
#include <stdio.h>

void addOne(int x) {
    printf("addOne(): x = %d\n", x);
    printf("addOne(): address of x = %p\n", &x);
    x = x + 1;         // แก้ x ใน function เท่านั้น
}

void addTwo(int *x_ptr) {
    printf("addTwo(): x_ptr = %p\n", x_ptr);
    printf("addTwo(): address of x_ptr = %p\n", &x_ptr);
    *x_ptr = *x_ptr + 2;        // dereference แล้วแก้ค่า ณ ที่อยู่นั้น
}

int main(void) {
    int number = 5;
    printf("main(): address of number: %p\n", &number);
    addOne(number);
    printf("main(): number = %d\n", number);   // ยังเป็น 5! เพราะ function ได้ "สำเนา" ไป
    addTwo(&number);
    printf("main(): number = %d\n", number); // ได้ค่าเท่าไร
    return 0;
}