#include <stdio.h>
#include <stdlib.h>
#include <time.h>
<<<<<<< HEAD
#include <omp.h> 
#define N 500  
#define THREADS 8

void matrixComputation(int A[N][N], int B[N][N], int C[N][N]) {
    #pragma omp parallel for schedule(static) collapse(2) 
=======
#include <omp.h> // Include OpenMP header
#define N 500  // Matrix size
#define THREADS 8 // Number of threads (adjust as needed)

void matrixComputation(int A[N][N], int B[N][N], int C[N][N]) {
    #pragma omp parallel for schedule(static) collapse(2) //Parallelizing outer loo
>>>>>>> static
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
void initializeMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
<<<<<<< HEAD
            matrix[i][j] = rand() % 10; 
=======
            matrix[i][j] = rand() % 10; // Assign a random value (0-9)
>>>>>>> static
        }
    }
}

int main() {
    srand(time(NULL)); 

    int A[N][N], B[N][N], C[N][N]; 
    initializeMatrix(A); 
    initializeMatrix(B); 

    omp_set_num_threads(THREADS);

    double total_time = 0.0;
    int runs = 10; 

    printf("Executing OpenMP matrix computation with %d threads, %d times...\n", THREADS, runs);
    
    for (int i = 0; i < runs; i++) {
        double start = omp_get_wtime(); 
        matrixComputation(A, B, C);
        double end = omp_get_wtime(); 

        double time_taken = end - start; 
        total_time += time_taken; 
        printf("Run for execution %d: %f seconds\n", i + 1, time_taken);
    }

    printf("\nAverage Execution Time with OpenMP: %f seconds\n", total_time / runs);
    return 0;
}