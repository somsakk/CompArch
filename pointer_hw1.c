// pointer_hw1.c
#include<stdio.h>

typedef struct contact {
    char name[20];
    int phone;
    unsigned int age;
} contact;

int main(void)
{
    contact my_contacts[3];
    
    printf("Sizes: sizeof(contact)=%#x, sizeof(my_contacts)=%#x, sizeof(my_contacts[0])=%#x\n", 
        (int)sizeof(contact), (int)sizeof(my_contacts), (int) sizeof(my_contacts[0]));
    printf("Length of my_contacsts: %d\n", (int)sizeof(my_contacts)/sizeof(my_contacts[0]));

    printf("Addresses of my_contacts[0]: %p\n", &my_contacts[0]);
    printf("Addresses of my_contacts[1]: %p\n", &my_contacts[1]);
    printf("Addresses of my_contacts[2]: %p\n", (my_contacts+2)); 
	// since (my_contacts+2) == &my_contacts[2]
     
    printf("Adddress:\n");
    for (int i=0; i<3; i++) {
        printf("\t&my_contacts[%d]: %p, &name: %p, &phone: %p, &age: %p\n", 
            i, (my_contacts+i), &(my_contacts[i].name), &(my_contacts[i].phone), &(my_contacts[i].age));  
        }   
}