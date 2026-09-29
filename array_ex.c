// array_ex.c
#include <stdio.h>

int main(void) {
    int numbers[5]; // ประกาศ array ขนาด 5 ช่อง (ยังไม่มีค่า )
    int scores[] = {90, 85, 70, 60, 95}; // ประกาศพร้อมใส่ค่า, ถ้ามีการให้ค่าเลย ไม่ต้องใส่ขนาดของ array ได้
    printf("scores[0] = %d\n", scores[0]); // เข้าถึงสมาชิก index 0 = 90
    printf("scores[4] = %d\n", scores[4]); // สมาชิกตัวสุดท้าย index 4 = 95
    printf("scores[5] = %d\n", scores[5]); // นี่หลุดจาก array แล้ว สามารถทำได้ แต่เป็น undefined behavior (อาจจะได้ค่าขยะ หรือ crash)
    
    scores[2] = 100; // เปลี่ยนค่าได้ (แต่ขนาด array เปลี่ยนไม่ได้)
    printf("size of scores[]: %d\n", (int) sizeof(scores)); //หาจำนวนไบต์ของ    scores[]
    printf("numbers[0] = %d\n", numbers[0]); // ยังไม่มีค่า (อาจจะ 0 หรือค่า    ขยะ)

    for (int i=0; i<7; i++) {
        printf("(%d,%d), ", i, scores[i]);
    }
    printf("\n");
    return 0;
}