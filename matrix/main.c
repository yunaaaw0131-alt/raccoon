#include <stdio.h>
#include "matrix_op.h"

void print_matrix(double M[SIZE][SIZE]) {
    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE;j++)
            printf("%8.3f ", M[i][j]);
        printf("\n");
    }
}

int main() {
    double A[3][3] = {{1,2,3},{0,1,4},{5,6,0}};
    double B[3][3] = {{7,8,9},{1,2,3},{4,5,6}};
    double R[3][3];

    mat_mul(A, B, R);
    print_matrix(R);

    return 0;
}
