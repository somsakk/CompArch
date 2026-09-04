//factorial_simple.c
#include <stdio.h>

// iterative function to calculate factorial
int fact(int n)
{
    int a=1;    
    for (int i=2; i <= n; i++) {
        a = a*i;    // same as a *= i;
    }
    return a;
}

int main()
{
    int num = 5;
    int result;
    result = fact(num);
    printf("%d! = %d\n", num, result);
    return 0;
}
