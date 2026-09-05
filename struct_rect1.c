/* struct_rect1.c
This program demonstrates the use of structures in C. 
It defines a point structure and a rectangle structure, and shows how to create instances of these structures, set their values, and print their sizes and addresses.
I also demonstrate how to access the members of a structure using the dot operator and how to use header files to declare structures and functions.
*/

#include "struct_rect.h" // our own header file to declare point and rect structures

int main() {
    int width = 2, height = 3; 

    // create a point p1(42,9) and a rectangle r1 with lower left corner at p1, width=2, height=3, color=1
    point p1;
    p1.x = 42; 
    p1.y = 9; // refer to elements inside a struct by a dot .
    
    rect r1;
    r1.ll = p1;     
    r1.color = 1;
    r1.ur.x = r1.ll.x + width;  
    r1.ur.y = r1.ll.y + height;

    // sizeof() operator returns the size of a variable or data type in bytes
    int s[] = {sizeof(p1), sizeof(r1), sizeof(int), sizeof(point), sizeof(rect)};
    for (int i=0; i<sizeof(s)/sizeof(s[0]); i++) {
        printf("s[%d] = %d, ", i, s[i]);
    }
    printf("\n");

    // print the coordinates of the point and rectangle
    printf("Coordinate of points: p1 = (%d, %d)\n", p1.x, p1.y);
    printf("r1.ll = (%d, %d), ", r1.ll.x, r1.ll.y);
    printf("r1.ur = (%d, %d)\n", r1.ur.x, r1.ur.y);

    // print address of point and rectangle and their members. 
    // We use (void *) to cast the address to a void pointer for printing.
    printf("Address of point p1 = %p\n", (void *)&p1);
    printf("\tAddress of p1.x = %p\n", (void *)&p1.x);
    printf("\tAddress of p1.y = %p\n", (void *)&p1.y);
    printf("Address of rect r1 = %p\n", (void *)&r1);
    printf("\tAddress of r1.ll = %p\n", (void *)&r1.ll);
    printf("\tAddress of r1.ll.x = %p\n", (void *)&r1.ll.x);
    printf("\tAddress of r1.ll.y = %p\n", (void *)&r1.ll.y);
    printf("\tAddress of r1.ur = %p\n", (void *)&r1.ur);
    printf("\tAddress of r1.color = %p\n", (void *)&r1.color);
}
