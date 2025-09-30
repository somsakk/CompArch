// malloc_ex.c
#include <stdlib.h> // for malloc and free functions

double* newMatrix(int m, int n) {
    double *mat;
    mat = (double*) malloc(m*n*sizeof(double));
    return mat;
}

double* newIdentityMatrix(int n) {
    double *mat = newMatrix(n, n);
    int i, j;
    for (i=0; i<n; i++)
    for (j=0; j<n; j++)
    mat[j+i*n] = (i==j);
    return mat;
}

int main(void) {
    int matrixSize;
    // ask user to enter the size of identity matrix
    printf("Enter the size of an identity matrix: ");
    scanf("%d", &matrixSize); // read in the entered value and assign to matrixSize
    // memory is allocated for some code to use this identity matrix
    double* iden = newIdentityMatrix(matrixSize);
    // deallocate the memory (don’t forget). Otherwise, memory leakage may occur.
    free(iden);
}