#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#define Size 500
#define N 3  
#define THREADS 4 
#define Run 10

void matrixComputation(int A[N][N], int B[N][N], int C[N][N]) {
    // Function to perform matrix multiplication using OpenMP with dynamic scheduling
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
void initializeMatrices(int A[Size][Size], int B[Size][Size]) {
    srand(50);  // Fixed seed for reproducibility
    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }
}
int main() {
    int A[Size][Size], B[Size][Size], C[Size][Size];
    initializeMatrices(A, B);  // Initialize matrices with random values

    double total_time = 0;

    for (int r = 0; r < Run; r++) {
        double start = omp_get_wtime();  // Start timing
        ParallelMatrixMultiplication(A, B, C);
        double end = omp_get_wtime();  // End timing

        double iteration_time = end - start;  // Compute execution time for this run
        total_time += iteration_time;  // Accumulate total time

        printf("Run %d: Execution Time = %f seconds\n", r + 1, iteration_time);
    }

    double avg_time = total_time / Run;
    printf("\nAverage Execution Time over %d runs: %f seconds\n", Run, avg_time);

    return 0;
}
