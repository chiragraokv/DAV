// Inplement on OpenMP program using the parallel for work sharing construct
// to perform the addition of thwo matrices of size mxn. Display the resultant matrix and the Thread ID responsible for computing each row. 
// Compare the execution time of the serial and the parallel implementation and comment on the distribution on the loop of iterations among the threads.
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main() {
    int m=3, n=3;
    printf("Name: Chirag Rao KV\n");
    printf("REG: 240962180\n");
    int A[m][n], B[m][n], C_serial[m][n], C_parallel[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = i + j;
            B[i][j] = i * j;
        }
    }
    double start, end;
    start = omp_get_wtime();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C_serial[i][j] = A[i][j] + B[i][j];
        }
    }
    end = omp_get_wtime();
    double serial_time = end - start;
    start = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < m; i++) {
        int tid = omp_get_thread_num();
        for (int j = 0; j < n; j++) {
            C_parallel[i][j] = A[i][j] + B[i][j];
        }
        printf("Row %d computed by Thread %d\n", i, tid);
    }
    end = omp_get_wtime();
    double parallel_time = end - start;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", C_parallel[i][j]);
        }
        printf("\n");
    }
    printf("Serial   : %f s\n", serial_time);
    printf("Parallel : %f d\n", parallel_time);
    return 0;
}