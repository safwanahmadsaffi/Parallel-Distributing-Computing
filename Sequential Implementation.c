#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 500  // Define the size of the matrices can be Adjusted as needed
// function perform matrixmultiplication
void matrixComputation(int A[N][N], int B[N][N], int C[N][N]) {
    //A First input matrix
    for (int i = 0; i < N; i++) {
        // B Second input matrix
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;      // Initialize result matrix cell
            // C Resultant matrix
            for (int k = 0; k < N; k++) {
                //dot product
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void initializeMatrix(int matrix[N][N]) {
    //Function to initialize a matrix with random values between 0-9
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 10;  //Assign  Random values between 0-9
        }
    }
}

int main() {
    srand(time(NULL)); //random number generation
    int A[N][N], B[N][N], C[N][N];
    initializeMatrix(A); //initilize matrix A
    initializeMatrix(B); ////initilize matrix B

    double total_time = 0.0;
    int runs = 10;

    for (int i = 0; i < runs; i++) {
        clock_t start = clock();        //START TIME
        matrixComputation(A, B, C);      //PEROFRM COMPUTATION
        clock_t end = clock();          //END TIME

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        total_time += time_taken;       //CALCULATE TOTAL TIME
        printf("Running for execution  %d: %f seconds\n", i + 1, time_taken);
    }

    printf("\nAverage Execution Time: %f seconds\n", total_time / runs);
    return 0;
}
