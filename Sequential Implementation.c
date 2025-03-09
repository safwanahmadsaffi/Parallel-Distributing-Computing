#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 500 

void matrixComputation(int A[N][N], int B[N][N], int C[N][N]) {
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
            matrix[i][j] = rand() % 10;  // Random values between 0-9
        }
    }
}

int main() {
    srand(time(NULL));
    int A[N][N], B[N][N], C[N][N];
    initializeMatrix(A);
    initializeMatrix(B);

    double total_time = 0.0;
    int runs = 10;

    for (int i = 0; i < runs; i++) {
        clock_t start = clock();
        matrixComputation(A, B, C);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        total_time += time_taken;
        printf("Run %d: %f seconds\n", i + 1, time_taken);
    }

    printf("\nAverage Execution Time: %f seconds\n", total_time / runs);
    return 0;
}
