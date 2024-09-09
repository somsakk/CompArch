// string_pointer_ex.c
#include <stdio.h>
#include <string.h>
int main() {
    char * name = "Somsak7"; // same as char name[] = "Somsak7";
    char* ch = name;
    for(int i = 0; i <= strlen(name); i++) { 
        printf("%c = %d = %#x,", *ch, *ch, *ch); 
        printf(" Address of the current character is ch = %p\n", ch);
        // printf("ch is pointing to %s\n", *ch);
        ch++;
    }
    printf("size of 'name' pointer = %d\n", (int) sizeof(name));  
    printf("length of %s = %d\n", name, (int) strlen(name));
    // printf("ch is pointing to %s\n", *ch); // causing segmentation fault.
}