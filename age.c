//age.c
#include <stdio.h> // ต้อง include ไฟล์ stdio.h ทีมีมาแล้วในไลบรารี่ เพื่อใช้ printf() ได้

int main(void) {
    int age = 21;
    float gpa = 3.75;
    char grade = 'A';

    printf("อายุ: %d\n", age);
    // %d = integer
    printf("GPA: %.2f\n", gpa);
    // %.2f = float ทศนิยม 2 ตําแหน่ง
    printf("เกรด: %c\n", grade);
    // %c = char
    printf("อายุ %d เกรด %c\n", age, grade); // ใส่หลายตัวได้

    return 0;
}
//
