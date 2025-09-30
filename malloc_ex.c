// malloc_ex.c
#include <stdio.h>
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

    printf("Address of the matrix is %p\n", iden);
    for (int i=0; i < matrixSize; i++) {
        for (int j=0; j < matrixSize; j++) {
            printf("%lf ", *(iden + i*matrixSize + j));
        }
        printf("\n");
    }
    printf("Address of the last element is %p\n", iden + matrixSize*matrixSize - 1);
    
    // deallocate the memory (don’t forget). Otherwise, memory leakage may occur.
    free(iden);
}
