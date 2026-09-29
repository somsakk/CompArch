//array_ex3.c
#include <stdio.h>
int main(void) {
    int scores[] = {10,20,30,40};
    int length = sizeof(scores) / sizeof(scores[0]);
    printf("length = %d\n", length);
    
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += scores[i]; // "+=" เป็นรูปย่อ เหมือน sum = sum + scores[i]
    }
    
    float average = (float)sum / length; // แปลง sum เป็น float ก่อนหาร
    printf("ผลรวม: %d\n", sum);
    printf("เฉลี่ย: %.2f\n", average);
    return 0;
}