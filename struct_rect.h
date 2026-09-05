// struct_rect.h
// This header file declares the point and rect structures, and the functions to set their values and print their details and addresses. 
// The functions are defined in struct_rect_helper.c and can be used in other files by including this header file.

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
