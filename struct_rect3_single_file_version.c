/* struct_rect3_single_file_version.c
This program demonstrates the use of structures in C. 
It defines a point structure and a rectangle structure, and shows how to create instances of these structures, set their values, and print their sizes and addresses.
I also demonstrate how to access the members of a structure using the dot operator and how to use header files to declare structures and functions.
*/

#include <stdio.h>
// a point is specified by (x,y) coordinate
typedef struct point {
    int x;
    int y;
} point;

// a rectangle is specified by the lower-left and upper-right points and color.
typedef struct rect {
    point ll;
    point ur;
    int color;
    char str[3];
} rect;

// Function prototypes for point and rect structures. 
void set_point(point *, int, int);
void print_point(point, char *);
void print_address_of_point(point *, char *); 

void set_rect(rect *, point, point, int);
void print_rect(rect, char *);
void print_address_of_rect(rect *, char *);

// Function prototype for printing the sizes of variables and data types.
void print_s (int *, int); 

int main() {
    int width = 2, height = 3; 
    printf("Addresses: width = %p, height = %p\n", (void *)&width, (void *) &height);

    // create a point p1(42,9) and a rectangle r1 with lower left corner at p1, width=2, height=3, color=1
    point p1, p2;
    // set the values of p1 using the function set_point(). 
    // Pass the address of p1 to the function, so that it can modify the original structure.
    set_point(&p1, 42, 9); 
    set_point(&p2, 45, 15); 

    // set the values of r1 using a function
    // To pass a point structure to the function set_rect(), we can use 
    // a compound literal (point){p1.x + width, p1.y + height} to create a temporary point structure 
    // with the desired values.
    rect r1;
    set_rect(&r1, p1, (point){p1.x + width, p1.y + height}, 1); 

    // sizeof() operator returns the size of a variable or data type in bytes
    printf("sizeof(point) = %d, sizeof(rect) = %d = %#x\n", (int) sizeof(point), (int) sizeof(rect), (int) sizeof(rect));
    int s[] = {sizeof(p1), sizeof(r1), sizeof(r1.str), sizeof(r1.str[0])};
    print_s(s, sizeof(s)/sizeof(s[0]));

    // print the coordinates of the point and rectangle
    print_point(p1, "p1");
    print_point(p2, "p2");
    print_rect(r1, "r1");

    // print address of point and rectangle and their members. 
    print_address_of_point(&p1, "p1");
    print_address_of_point(&p2, "p2");
    print_address_of_rect(&r1, "r1");
    // Students' exercise: create more instances of point and rect structures, and use the functions to set their values and print their details and addresses.
    // Let r2 be a rectangle with lower left corner at (10,20) and upper right corner at p2, color=2.
    // Let r3 be a rectangle with the same values as r1. Note we can copy the values of a structure to another structure of the same type using the assignment operator =.  
    // That is we can do r3 = r1; to copy the values of r1 to r3.
    // (write your code here)
    rect r2, r3;
    set_rect(&r2, (point){10,20}, p2, 1);
    r3 = r1;
    print_rect(r2, "r2");
    print_rect(r3, "r3");
    print_address_of_rect(&r2, "r2");
    print_address_of_rect(&r3, "r3");

    printf("\nTest accessing any part of the memory:\n");
    int *base_addr = (int*) &p1;
    if (&p2 < &p1) {
        base_addr = (int*) &p2;
        printf("&p2 < &p1\n");
    }
    printf("base_addr = %p\n", (void *) base_addr);
    printf("Before:\n");
    print_point(p1, "p1"); print_point(p2, "p2");    
    // change adjacent point to (100,200). In practice, don't do this. 
    *(base_addr+2) = 100; *(base_addr+3) = 200;   
    printf("After:\n");
    print_point(p1, "p1"); print_point(p2, "p2");
}

// Function to set the values of a point. 
// We need to pass a pointer to the point structure, so that we can modify the original structure.
// For pointer, we use the arrow operator -> to access the members of the structure.
void set_point(point *p_ptr, int x, int y) {
    p_ptr->x = x;
    p_ptr->y = y;
}

// Function to print the details of a point. 'name' is a string to identify the point in the output.
// No need to pass a pointer to the point structure, since we are only reading its values.
void print_point(point p, char *name) {
    printf("%s: (%d, %d)\n", name, p.x, p.y);
}

// Function to print the addresses of a point and its members
void print_address_of_point(point *p_ptr, char *name) {
    printf("Address of point %s = %p\n", name, (void *)p_ptr);
    printf("\tAddress of %s.x = %p\n", name, (void *)&p_ptr->x);
    printf("\tAddress of %s.y = %p\n", name, (void *)&p_ptr->y);
}

// Function to set the values of a rectangle
void set_rect(rect *r_ptr, point ll, point ur, int color) {
    r_ptr->ll = ll;
    r_ptr->ur = ur;
    r_ptr->color = color;
}

// Function to print the details of a rectangle. 'name' is a string to identify the rectangle in the output.
void print_rect(rect r, char *name) {
    printf("%s: ll = (%d, %d), ur = (%d, %d), color = %d\n", name,
           r.ll.x, r.ll.y, r.ur.x, r.ur.y, r.color);
}

// Function to print the addresses of a rectangle and its members
void print_address_of_rect(rect *r_ptr, char *name) {
    printf("Address of rect %s = %p\n", name, (void *)r_ptr);
    printf("\tAddress of %s.ll = %p\n", name, (void *)&r_ptr->ll);
    printf("\tAddress of %s.ll.x = %p\n", name, (void *)&r_ptr->ll.x);
    printf("\tAddress of %s.ll.y = %p\n", name, (void *)&r_ptr->ll.y);
    printf("\tAddress of %s.ur = %p\n", name, (void *)&r_ptr->ur);
    printf("\tAddress of %s.color = %p\n", name, (void *)&r_ptr->color);
    printf("\tAddress of %s.str = %p\n", name, (void *)&r_ptr->str);
    int str_len = sizeof(r_ptr->str)/sizeof(r_ptr->str[0]);
    // int str_len = sizeof(r_ptr->str)/sizeof(*(r_ptr->str)); // same as above
    printf("\tAddress of %s.str[%d] = %p\n", name, str_len-1, (void *)&(r_ptr->str[str_len-1]));
}

void print_s (int *s, int len) {
    for (int i=0; i<len; i++) {
        printf("s[%d] = %d, ", i, s[i]); // same as below since s[i] == *(s+i)
        // printf("s[%d] = %d, ", i, *(s+i));
    }
    printf("\n");
}