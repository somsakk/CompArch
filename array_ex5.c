//array_ex5.c
#include <stdio.h>
int main(void) {
    char name[20] = "Somchai"; // จองที่ 20 ช่อง เก็บ "Somchai" + \0 อัตโนมัติ
    // char name[] = "Somchai"; // จองที่เท่าที่จำเป็น เก็บ "Somchai" + \0 อัตโนมัติ
    // char name[] = "abcABC123"; 
    printf("%s\n", name); // %s สำหรับ string
    
    int length = sizeof(name)/sizeof(name[0]);
    printf("length of name[] is %d bytes\n", length);
    
    for (int i = 0; i < length; i++) {
        printf("name[%d] = %d = %c = %#x\n", i, name[i], name[i], name[i]);
    }
    return 0;
}