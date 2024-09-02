// global_to_local_ex.c
#include <stdio.h>
int function1(int function1_count) {
    printf("Function 1 called.\n");
    return (++function1_count); // Increment the global counter for function1
}

int function2(int function2_count) {
    printf("Function 2 called.\n");
    return (++function2_count);
}
int main() {
    int function1_count = 0;  // local variables
    int function2_count = 0;
    function1_count = function1(function1_count); // Call the functions multiple times
    function2_count = function2(function2_count);
    function1_count = function1(function1_count);
    function1_count = function1(function1_count);
    function2_count = function2(function2_count);
    printf("Function 1 was called %d times.\n", function1_count);
    printf("Function 2 was called %d times.\n", function2_count);
}



