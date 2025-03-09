#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#define N 500  
#define THREADS 4 
void matrixComputation(int A[N][N], int B[N][N], int C[N][N]) {
    #pragma omp parallel for schedule(dynamic) collapse(2) 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                #pragma omp atomic
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
void initializeMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 10;  // Assign a random value (0-9)
        }
    }
}
