// factorial.c
#include <stdio.h>

int fact(int n) {
  int result;
  if (n <= 1) {
    result = 1;
  } 
  else {
    result = n*fact(n-1);
  }
  return result;
}

int main(void) {
  int a = 5;
  int result;
  result = fact(a);
  printf("factorial of %d is %d\n", a, result);
}
