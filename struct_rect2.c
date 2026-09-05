/* struct_rect2.c
This program demonstrates the use of structures in C. 
It defines a point structure and a rectangle structure, and shows how to create instances of these structures, set their values, and print their sizes and addresses.
I also demonstrate how to access the members of a structure using the dot operator and how to use header files to declare structures and functions.

Modified from struct_rect1.c to use functions to set the values of point and rect structures, and to print their values and addresses.
The functions are declared in struct_rect.h and defined in struct_rect_helper.c.
We create more instances of point and rect structures, and use the functions to set their values and print their details and addresses.
*/

#include "struct_rect.h" // our own header file to declare point and rect structures

int main() {
    int width = 2, height = 3; 

    // create a point p1(42,9) and a rectangle r1 with lower left corner at p1, width=2, height=3, color=1
    point p1;
    // set the values of p1 using the function set_point(). 
    // Pass the address of p1 to the function, so that it can modify the original structure.
    set_point(&p1, 42, 9); 

    // set the values of r1 using a function
    // To pass a point structure to the function set_rect(), we can use 
    // a compound literal (point){p1.x + width, p1.y + height} to create a temporary point structure 
    // with the desired values.
    rect r1;
    set_rect(&r1, p1, (point){p1.x + width, p1.y + height}, 1); 

    // sizeof() operator returns the size of a variable or data type in bytes
    int s[] = {sizeof(p1), sizeof(r1), sizeof(int), sizeof(point), sizeof(rect)};
    print_s(s, sizeof(s)/sizeof(s[0]));

    // print the coordinates of the point and rectangle
    print_point(p1, "p1");
    print_rect(r1, "r1");

    // print address of point and rectangle and their members. 
    print_address_of_point(&p1, "p1");
    print_address_of_rect(&r1, "r1");

    // Students' exercise: create more instances of point and rect structures, and use the functions to set their values and print their details and addresses.
    // Let r2 be a rectangle with lower left corner at (10,20) and upper right corner at p1, color=2.
    // Let r3 be a rectangle with the same values as r1. Note we can copy the values of a structure to another structure of the same type using the assignment operator =.  
    // That is we can do r3 = r1; to copy the values of r1 to r3.
    // (write your code here)
}
