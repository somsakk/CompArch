// pointer_double.c
#include <stdio.h>

void doubleAll(int arr[], int length) {
// void doubleAll(int *arr, int length) { // หรือแบบนี้ 
    for (int i = 0; i < length; i++) {
        arr[i] = arr[i] * 2;    // แก้ต้นฉบับได้เลย ไม่ต้องใช้ &
        // *(arr + i) = *(arr + i) * 2; // หรือแบบนี้
    }
}

int main(void) {
    int nums[3] = {1, 2, 3};
    doubleAll(nums, 3);
    printf("%d %d %d\n", nums[0], nums[1], nums[2]);   // 2 4 6
    return 0;
}