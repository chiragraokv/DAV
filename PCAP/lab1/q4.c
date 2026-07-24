// Implement an OpenMP program to perform the addition of two one-dimensional arrays of
// size N using the parallel for directive. Display the resulting array and identify the Thread
// ID that computes each array element.

#include <stdio.h>
#include <omp.h>
#define N 10 
int main() {
    int A[N], B[N], C[N];
    int thread_tracking[N]; 

    for (int i = 0; i < N; i++) {
        A[i] = (i + 1) * 2; 
        B[i] = (i + 1);      
    }
    #pragma omp parallel for shared(A, B, C, thread_tracking)
    for (int i = 0; i < N; i++) {
        C[i] = A[i] + B[i];
        thread_tracking[i] = omp_get_thread_num();
    }


    for (int i = 0; i < N; i++) {
        printf("%-8d + %-8d = %-8d | Thread ID: %d\n", 
               A[i], B[i], C[i], thread_tracking[i]);
    }

    return 0;
}

