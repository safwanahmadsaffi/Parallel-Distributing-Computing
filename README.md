# Performance Analysis of OpenMP-based Matrix Computation

## Overview
This project implements and analyzes matrix multiplication using OpenMP in three different configurations:
- **Sequential:** Basic implementation using nested loops without parallelization.
- **Static Scheduling:** Uses OpenMP with `#pragma omp parallel for schedule(static) collapse(2)`, ensuring equal workload distribution among threads.
- **Dynamic Scheduling:** Uses OpenMP with `#pragma omp parallel for schedule(dynamic) collapse(2)`, allowing dynamic assignment of work to threads.

## Features
- Implements matrix multiplication in three configurations.
- Measures execution time using `clock()` (for sequential) and `omp_get_wtime()` (for OpenMP versions).
- Compares execution times to analyze performance.

## Installation
### Prerequisites
- GCC Compiler with OpenMP support
- C or C++ development environment

### Compilation
To compile the code with OpenMP support, use the following command:
```sh
gcc -fopenmp matrix_multiplication.c -o matrix_multiplication
```

## Usage
Run the compiled program:
```sh
./matrix_multiplication
```

## Results
The program records execution times for each approach and provides insights into the performance of different scheduling strategies.

### Sample Execution Times (in seconds):
| Run | Sequential | Static | Dynamic |
|------|-----------|--------|---------|
| 1    | 0.156723  | 0.151680 | 2.207892 |
| 2    | 0.175893  | 0.147532 | 2.216900 |
| 3    | 0.171717  | 0.200633 | 2.227462 |
| 4    | 0.192261  | 0.146291 | 2.205987 |
| 5    | 0.154638  | 0.193059 | 2.188966 |
| 6    | 0.166033  | 0.146483 | 2.220461 |
| 7    | 0.204680  | 0.174229 | 2.289360 |
| 8    | 0.167344  | 0.158316 | 2.271160 |
| 9    | 0.175134  | 0.155547 | 2.267059 |
| 10   | 0.162018  | 0.194265 | 2.947300 |

**Average Execution Time:**
- **Sequential:** 0.172644 sec
- **Static:** 0.166804 sec
- **Dynamic:** 2.274695 sec

## Observations
- **Static scheduling** performed best, slightly improving execution time over the sequential version.
- **Dynamic scheduling** was significantly slower due to overhead in task allocation.
- **Parallelization impact:** OpenMP improved performance, but scheduling strategy played a critical role.

## Challenges & Lessons Learned
- **Thread Overhead:** Dynamic scheduling introduced excessive overhead.
- **Memory Considerations:** Efficient memory handling is essential to avoid cache misses.
- **Optimization Trade-offs:** Not all parallelization strategies improve performance.

## Future Improvements
- Implement **block-wise matrix multiplication** to optimize memory usage.
- Explore **hybrid scheduling** to balance workload distribution.

## License
This project is licensed under the MIT License.

## Author
[Your Name]

