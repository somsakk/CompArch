// struct_ex2.c 
// #include "struct_ex.h" // ok if we run locally

// but to run in onlinegdb or godbolt, we need to put everything in a single file
#include <stdio.h>
#include <stdint.h>

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

void createRect(int x1, int y1, int width, 
                int height, int color, rect *r) {
    r->ll.x = x1; 
    r->ll.y = y1; 
    r->ur.x = x1 + width; 
    r->ur.y = y1 + height;
    r->color = color;
}
 
int main(void) {
    // r1 and r2 denote rectangle of the same widht 
    // and height, but at different locations
    rect r1, r2;
    createRect(3, 5, 10, 20, 1, &r1);
    createRect(2, 8, 10, 20, 1, &r2);
    printf("Address of r1 is %p\n", &r1);
    printf("Address of r2 is %p\n", &r2);
    printf("r1: ur=(%d,%d)\n", r1.ur.x, r1.ur.y);
    printf("r2: ur=(%d,%d)\n", r2.ur.x, r2.ur.y);
}