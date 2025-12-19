#include "matrix_op.h"

/* Addition */
void mat_add(double A[SIZE][SIZE], double B[SIZE][SIZE], double R[SIZE][SIZE]) {
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++)
            R[i][j] = A[i][j] + B[i][j];
}

/* Subtraction */
void mat_sub(double A[SIZE][SIZE], double B[SIZE][SIZE], double R[SIZE][SIZE]) {
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++)
            R[i][j] = A[i][j] - B[i][j];
}

/* Element-wise multiplication */
void mat_elem_mul(double A[SIZE][SIZE], double B[SIZE][SIZE], double R[SIZE][SIZE]) {
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++)
            R[i][j] = A[i][j] * B[i][j];
}

/* Matrix multiplication */
void mat_mul(double A[SIZE][SIZE], double B[SIZE][SIZE], double R[SIZE][SIZE]) {
    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE;j++) {
            R[i][j] = 0;
            for(int k=0;k<SIZE;k++)
                R[i][j] += A[i][k] * B[k][j];
        }
    }
}

/* Transpose */
void mat_transpose(double A[SIZE][SIZE], double R[SIZE][SIZE]) {
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++)
            R[j][i] = A[i][j];
}

/* Determinant (3x3) */
double mat_det(double A[SIZE][SIZE]) {
    return
        A[0][0]*(A[1][1]*A[2][2] - A[1][2]*A[2][1]) -
        A[0][1]*(A[1][0]*A[2][2] - A[1][2]*A[2][0]) +
        A[0][2]*(A[1][0]*A[2][1] - A[1][1]*A[2][0]);
}

/* Adjoint */
void mat_adjoint(double A[SIZE][SIZE], double R[SIZE][SIZE]) {
    R[0][0] =  (A[1][1]*A[2][2] - A[1][2]*A[2][1]);
    R[0][1] = -(A[1][0]*A[2][2] - A[1][2]*A[2][0]);
    R[0][2] =  (A[1][0]*A[2][1] - A[1][1]*A[2][0]);

    R[1][0] = -(A[0][1]*A[2][2] - A[0][2]*A[2][1]);
    R[1][1] =  (A[0][0]*A[2][2] - A[0][2]*A[2][0]);
    R[1][2] = -(A[0][0]*A[2][1] - A[0][1]*A[2][0]);

    R[2][0] =  (A[0][1]*A[1][2] - A[0][2]*A[1][1]);
    R[2][1] = -(A[0][0]*A[1][2] - A[0][2]*A[1][0]);
    R[2][2] =  (A[0][0]*A[1][1] - A[0][1]*A[1][0]);
}

/* Inverse */
int mat_inverse(double A[SIZE][SIZE], double R[SIZE][SIZE]) {
    double det = mat_det(A);
    if(det == 0) return 0;

    double adj[SIZE][SIZE];
    mat_adjoint(A, adj);

    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++)
            R[i][j] = adj[j][i] / det;  // transpose(adj)/det

    return 1;
}
