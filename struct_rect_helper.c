/* struct_rect_helper.c
This file contains the implementations of the functions declared in struct_rect.h.
If we want to use these functions in other files, we need to include struct_rect.h in those files.

When we create a point or rect structure, we can use the functions in this file to set their values and print their details and addresses.
*/

#include "struct_rect.h" // point and rect structures are declared there

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
}

void print_s (int *s, int len) {
    for (int i=0; i<len; i++) {
        printf("s[%d] = %d, ", i, s[i]);
    }
    printf("\n");
}