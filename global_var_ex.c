// global_var_ex.c
#include <stdio.h>
int function1_count = 0;  // Global variables
int function2_count = 0;

void function1() {
    function1_count++; // Increment the global counter for function1
    printf("Function 1 called.\n");
}

void function2() {
    function2_count++;
    printf("Function 2 called.\n");
}

int main() {
    function1(); // Call the functions multiple times
    function2();
    function1();
    function1();
    function2();
    printf("Function 1 was called %d times.\n", function1_count);
    printf("Function 2 was called %d times.\n", function2_count);
}



