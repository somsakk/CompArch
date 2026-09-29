// pointer_array0.c
#include <stdio.h>

int main(void) {
    // int scores[] = {11, 12, 13, 14}; // ประกาศพร้อมใส่ค่า, ถ้ามีการให้ค่าเลย ไม่ต้องใส่ขนาดของ array ได้
    int scores[] = {11, 12};
    
    int len_scores = sizeof(scores) / sizeof(scores[0]);
    printf("len_scores = %d\n", len_scores);
    
    for (int i=0; i<len_scores; i++) {
        printf("scores[%d] = %d, address %p\n", i, scores[i], &scores[i]);
    }

    // We can go outside the scope of array
    printf("\n**Outside the scope of array:\n");
    for (int i=len_scores; i < (len_scores + 2); i++) {
        printf("scores[%d] = %d, address %p\n", i, scores[i], &scores[i]);
    }
    printf("scores[-1] = %d, address %p\n", scores[-1], &scores[-1]);
    return 0;
}