/* bit_manipulation2.c
This program continues from bit_manipulation1.c and demonstrates additional bit manipulation operations in C.
It includes examples of left and right bit shifts, as well as clearing specific bits.
*/
#include <stdio.h>
int main() {
    unsigned int num = 0x23; // Example number
    printf("Original number: %u or %#x\n", num, num);

    // Left bit shift by 2 positions
    unsigned int left_shifted = num << 2;
    printf("If left shift by 2: %#x\n", left_shifted);

    // Right bit shift by 2 positions
    unsigned int right_shifted = num >> 2;
    printf("If right shift by 2: %#x\n", right_shifted);    

    // Let's change num. Clearing the least significant bit
    num &= ~1;
    printf("After clearing the least significant bit: num = %#x\n", num);

    // Clearing the sixth least significant bit
    num &= ~(1 << 5);
    printf("After clearing the sixth least significant bit: num = %#x\n", num);

    // setting the third least significant bit
    num |= (1 << 2);
    printf("After setting the third least significant bit: num = %#x\n", num);

    // Toggling the fourth least significant bit
    num ^= (1 << 3);
    printf("After toggling the fourth least significant bit: num = %#x\n", num);

    // Let's put operations together, e.g., make the second byte of num to be 0xAB
    num &= ~(0xff << 8); // Clear the second byte
    num |= (0xAB << 8);  // Set the second byte to 0xAB
    printf("After setting the second byte to 0xAB: num  = %#x\n", num);

    // Get the second byte by right shift by 8 and mask with 0xff
    unsigned int second_byte = (num >> 8) & 0xff;
    printf("The second byte of num is: %#x\n", second_byte);

    return 0;
}