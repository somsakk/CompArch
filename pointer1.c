// pointer1.c
#include <stdio.h>

int main(void) {
   
    int age = 21;
    int *ptr = &age;    // ptr เก็บที่อยู่ของ age

    printf("%d\n", age);     // 21 (ค่าปกติ)
    printf("&age = %p\n", &age);    // ที่อยู่ของ age
    printf("ptr = %p\n", ptr);     // ที่อยู่ของ age (เหมือนกัน! เพราะ ptr เก็บที่อยู่นี้ไว้)
    printf("%d\n", *ptr);    // 21 (ค่า ณ ที่อยู่ที่ ptr ชี้ไป)

    printf("&ptr = %p\n", &ptr);     // ที่อยู่ของ ptr 
    printf("sizeof(ptr) = %d\n", sizeof(ptr));  // ขนาดของ pointer

    // add these lines
    *ptr = 25;              // เปลี่ยนค่า ณ ที่อยู่ที่ ptr ชี้ไป
    printf("%d\n", age);    // 25! เพราะ ptr ชี้ไปที่ age ตัวเดียวกัน
        
    return 0;
}