// factorial_address.c
// This program computes the factorial of a number using both iterative and recursive methods.
// It also prints the addresses of variables and functions to demonstrate memory allocation.
// The addresses of local variables are on the stack, while global variables and functions are in the data segment.
// We can also see the difference in stack usage between iterative and recursive approaches.
// Repeated calls to the iterative function do not create new stack frames, while recursive calls do.

#include <stdio.h>

// Function prototypes. If the function is defined after main(), we need to declare it first.
int fact_i(int);
int fact_r(int);

// create global variable for testing address of global variable
int b = 0;

int main(void) {
  char cc = 'A';
  int n = 4;  // Overflow happens with a >= 28
  int f[3]; // array to hold factorial results

  // size_of() operator returns the size of a variable or data type in bytes
  printf("sizeof(char) = %d, size of(int) = %d\n", (int) sizeof(char), (int) sizeof(int));
  printf("sizeof(cc) = %d, size of(n) = %d, size_of(f) = %d\n\n", (int) sizeof(cc), (int) sizeof(n), (int) sizeof(f));
  // printf("Address is %d bytes\n", (int) sizeof(&cc));

  // Print addresses of local variables and global variable
  printf("Addresses: &cc = %p, &n = %p\n", (void*)&cc, (void*)&n);
  // array name is a pointer to the first element of the array, so &f[0] and f are the same address. Let's check.
  printf("Addresses: f = %p,  &f[0] = %p, &f[1] = %p, &f[2] = %p\n", (void*)f, (void*)&f[0], (void*)&f[1], (void*)&f[2]);
  printf("Address of global variable b = %p\n\n", (void*)&b);

  // Print addresses of functions. Functions also have addresses, which can be printed using the function name
  printf("Address of function main() = %p\n", (void*)main);
  printf("Address of function fact_i() = %p\n", (void*)fact_i);
  printf("Address of function fact_r() = %p\n\n", (void*)fact_r);
  
  // Call the iterative factorial function and store the result in f[0]
  f[0] = fact_i(n) + b;
  printf("**main(): Iterative factorial of %d is %d\n", n, f[0]);

  // Call the recursive factorial function and store the result in f[1]
  // f[1] = fact_r(n);
  // printf("**main(): Recursive factorial of %d is %d\n", n, f[1]);

  // Call the iterative factorial function with n+1 and store the result in f[2]
  // f[2] = fact_i(n+1);    
  // printf("**main(): Iterative factorial of %d is %d\n", n+1, f[2]);
}

// Iterative factorial function
int fact_i(int n) {
  int ans=1;
  printf("in fact_i(n = %d): &n = %p\n", n, (void*)&n);

  for (int i = 2; i <= n; i++) {
    ans *= i;    
  }
  printf("in fact_i(n = %d): ans = %d, &ans = %p\n", n, ans, (void*)&ans);
  return ans;
}

// Recursive factorial function
int fact_r(int n) {
  int ans = -1;

  printf("in fact_r(n=%d), &n = %p\n", n, (void*)&n);
  printf("\tin fact_r(n=%d): &ans = %p\n", n, (void*)&ans);
  
  if (n <= 1) {
    printf("\tbase case reached: n=%d, returning 1.\n", n);
    ans = 1;
  } 
  else {
    printf("\tcalling fact_r(n=%d)\n", n-1);
    ans = n * fact_r(n-1);
  }
  printf("in fact_r(n=%d): ans = %d, &ans = %p\n", n, ans, (void*)&ans);
  return ans;
}