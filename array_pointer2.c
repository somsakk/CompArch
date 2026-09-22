// array_pointer2.c
#include<stdio.h>
#include<stdint.h>

// 
int main(void)
{
    // int32_t ar[3] = {93, 81, 97};
    int32_t ar[3] = {0x12345678, 0xdeadbeef, 97};  
    int len = sizeof(ar)/sizeof(ar[0]);

    for (int i=0; i < len; i++) {
        printf("ar[%d] = %#08x = %10d, address is %p\n", i, ar[i], *(ar+i), ar+i);
    }

    int clen = 4*2;
    // read one byte at a time
    uint8_t *cptr = (uint8_t *) ar; // type cast ar which is (int32_t *) to (unit8_t *) pointer.
    for (int i = 0; i < clen; i++) {
        printf("byte %d: address: %p, value: %#8x = %3u\n", i, cptr+i, *(cptr+i), *(cptr+i));
        // printf("byte %d: address: %p, value: %#8x = %3u\n", i, cptr, *cptr, *cptr);
        // cptr++;
    }

    // read two bytes at a time
    uint16_t *dptr = (uint16_t *) ar; // type cast ar which is (int32_t *) to (uint16_t *) pointer.
    for (int i = 0; i < clen; i++) {
        printf("%d: address: %p, value: %#8x = %3u\n", i, dptr+i, *(dptr+i), *(dptr+i));
    }
}
