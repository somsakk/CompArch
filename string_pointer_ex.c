// string_pointer_ex.c
#include <stdio.h>
#include <string.h>
int main() {
    char *name = "abc1"; // same as char name[] = "abc1";
    char *ch = name; // ch also points to the first element of the string.
    printf("size of 'name' pointer = %d\n", (int) sizeof(name));  
    printf("length of %s = %d\n\n", name, (int) strlen(name));
    
    for(int i = 0; i <= strlen(name); i++) { 
        printf("length of %s = %d\n", ch, (int) strlen(ch));
        printf("%c = %d = %#x,", *ch, *ch, *ch); 
        printf("\tAddress of this character is %p\n\n", ch);
        ch++;
        // equivalent to
        printf("length of %s = %d\n", &name[i], (int) strlen(&name[i]));
        // printf("length of %s = %d\n", name+i, (int) strlen(name+i));
        printf("%c = %d = %#x,", name[i], name[i], name[i]); 
        printf("\tAddress of this character is %p\n\n", &name[i]);
        // We can also use (name+i) in place of &name[i]        
    }
}