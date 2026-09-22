/* struct_rect5_single_file_version.c
This program demonstrates the use of structures in C. 
It defines a point structure and a rectangle structure, and shows how to create instances of these structures, set their values, and print their sizes and addresses.
I also demonstrate how to access the members of a structure using the dot operator and how to use header files to declare structures and functions.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// a point is specified by (x,y) coordinate
typedef struct point {
    int x;
    int y;
    char name[4];  
} point;

// a rectangle is specified by the lower-left and upper-right points and color.
typedef struct rect {
    point ll;
    point ur;
    int color;
    char name[4];
} rect;

// Function prototypes for point and rect structures. 
void set_point(point *, int, int, char *);
void print_point(point);
void print_address_of_point(point *); 

void set_rect(rect *, point, point, int, char *);
void print_rect(rect);
void print_address_of_rect(rect *);
// Function prototype for printing the sizes of variables and data types.
void print_s (int *, int); 

int main() {
    int width = 2, height = 3; 
    printf("Addresses: width = %p, height = %p\n", (void *)&width, (void *) &height);

    int N=4;
    // point p[N]; 
    // rect r[N];

    point* p = (point*)malloc(N * sizeof(point));
    rect* r = (rect*)malloc(N * sizeof(rect));

    char buffer[4];

    int s[] = {sizeof(point), sizeof(rect), sizeof(p), sizeof(r)};
    print_s(s, sizeof(s)/sizeof(s[0]));

    for (int i=0; i<N; i++) { 
        sprintf(buffer, "p%d",i); 
        set_point(&p[i], 40+i, 10+i, buffer); 
        print_point(p[i]);
        print_address_of_point(&p[i]);
    }
    
    for (int i=0; i<N; i++) { 
        sprintf(buffer, "r%d",i); 
        set_rect(&r[i], p[i], (point){p[i].x + width, p[i].y + height, ""}, 1, buffer); 
        print_rect(r[i]);
        print_address_of_rect(&r[i]);
    }

    free(p);
    free(r);
    return 0;
}

// Function to set the values of a point. 
// We need to pass a pointer to the point structure, so that we can modify the original structure.
// For pointer, we use the arrow operator -> to access the members of the structure.
void set_point(point *p_ptr, int x, int y, char *name) {
    p_ptr->x = x;
    p_ptr->y = y;
    strcpy(p_ptr->name, name);    
}

// Function to print the details of a point. 'name' is a string to identify the point in the output.
// No need to pass a pointer to the point structure, since we are only reading its values.
void print_point(point p) {
    printf("%s: (%d, %d)\n", p.name, p.x, p.y);
}

// Function to print the addresses of a point and its members
void print_address_of_point(point *p_ptr) {
    printf("Address of point %s = %p\n", p_ptr->name, (void *)p_ptr);
    printf("\tAddress of %s.x = %p\n", p_ptr->name, (void *)&p_ptr->x);
    printf("\tAddress of %s.y = %p\n", p_ptr->name, (void *)&p_ptr->y);
    printf("\tAddress of %s.name = %p\n", p_ptr->name, (void *)p_ptr->name);
}

// Function to set the values of a rectangle
void set_rect(rect *r_ptr, point ll, point ur, int color, char *name) {
    r_ptr->ll = ll;
    r_ptr->ur = ur;
    r_ptr->color = color;
    strcpy(r_ptr->name, name);  
}

// Function to print the details of a rectangle. 'name' is a string to identify the rectangle in the output.
void print_rect(rect r) {
    printf("%s: ll = (%d, %d), ur = (%d, %d), color = %d\n", r.name,
           r.ll.x, r.ll.y, r.ur.x, r.ur.y, r.color);
}

// Function to print the addresses of a rectangle and its members
void print_address_of_rect(rect *r_ptr) {
    printf("Address of rect %s = %p\n", r_ptr->name, (void *)r_ptr);
    printf("\tAddress of %s.ll = %p\n", r_ptr->name, (void *)&r_ptr->ll);
    printf("\tAddress of %s.ll.x = %p\n", r_ptr->name, (void *)&r_ptr->ll.x);
    printf("\tAddress of %s.ll.y = %p\n", r_ptr->name, (void *)&r_ptr->ll.y);
    printf("\tAddress of %s.ur = %p\n", r_ptr->name, (void *)&r_ptr->ur);
    printf("\tAddress of %s.color = %p\n", r_ptr->name, (void *)&r_ptr->color);
    printf("\tAddress of %s.name = %p\n", r_ptr->name, (void *)r_ptr->name);
}

void print_s (int *s, int len) {
    for (int i=0; i<len; i++) {
        printf("s[%d] = %d, ", i, s[i]); // same as below since s[i] == *(s+i)
        // printf("s[%d] = %d, ", i, *(s+i));
    }
    printf("\n");
}