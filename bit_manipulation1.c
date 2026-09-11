/* bit_manipulation1.c
This program demonstrates basic bit manipulation operations in C.
It includes examples of bitwise AND, OR, XOR, and NOT operations.
The program checks the least significant bit of a number, sets it, toggles it, and inverts all bits. 
*/

#include <stdio.h>

int main() {
    unsigned int num = 0x2e; // Example number
    printf("Original number: %u or %#x\n", num, num);

    // Bitwise AND with 1 to check if the least significant bit is set
    if (num & 1) {
        printf("The least significant bit is set (odd number).\n");
    } else {
        printf("The least significant bit is not set (even number).\n");
    }

    // Bitwise OR to set the least significant bit
    num |= 1;
    printf("After setting the least significant bit: %#x\n", num);

    // Bitwise XOR to toggle the least significant bit
    num ^= 1;
    printf("After toggling the least significant bit: %#x\n", num);

    // Bitwise NOT to invert all bits
    unsigned int inverted = ~num;
    printf("Inverted number: %u or %#x\n", inverted, inverted);

    return 0;
}