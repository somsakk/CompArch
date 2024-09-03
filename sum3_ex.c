// sum3_ex.c
#include <stdio.h>

// calculate the sum of the inputs
int sum3(int a, int b, int c) {
  int sum = a + b + c;
  printf("In sum3(), a = %d\n", a);
  return sum;
}

int main(void) {
  int a=7;
  printf("In main(), a = %d\n", a); 
  a = sum3(3, a, 2);
  printf("In main(), a = %d\n", a); 
}
