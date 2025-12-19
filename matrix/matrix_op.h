#ifndef MATRIX_OP_H
#define MATRIX_OP_H

#define SIZE 3

/* Basic operations */
void mat_add(double A[SIZE][SIZE], double B[SIZE][SIZE], double R[SIZE][SIZE]);
void mat_sub(double A[SIZE][SIZE], double B[SIZE][SIZE], double R[SIZE][SIZE]);
void mat_elem_mul(double A[SIZE][SIZE], double B[SIZE][SIZE], double R[SIZE][SIZE]);

/* Linear operations */
void mat_mul(double A[SIZE][SIZE], double B[SIZE][SIZE], double R[SIZE][SIZE]);
void mat_transpose(double A[SIZE][SIZE], double R[SIZE][SIZE]);

/* Advanced operations */
double mat_det(double A[SIZE][SIZE]);
void mat_adjoint(double A[SIZE][SIZE], double R[SIZE][SIZE]);
int mat_inverse(double A[SIZE][SIZE], double R[SIZE][SIZE]);

#endif
