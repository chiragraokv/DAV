// Implement a C program using OpenMp to process an integer array in parallel and demonstrate the use of the following synchronization constructs
// critical 
// atomic 
// reduction 
// master

// The programme should perform the following task
// 1. The master thread should initialize the array and display the total number of threads participating in the computation.
// 2. Use the reduction clause to compute the sum of all the array in parallel
// 3. Use the atomic construct to allow each thread to safely display its thread ID and the partial sum of the array elemnts processed
// 4. After all threads complete execution, the master thread should display the final sum of the array elements and the total count of even numbers.
#include <stdio.h>
#include <omp.h>

int main() {
    int a[10], sum = 0, even = 0, pSum = 0, n = 10;
    printf("Name: Chirag Rao KV\n");
    printf("REG: 240962180\n");
    #pragma omp parallel
    {
        #pragma omp master
        {
            for (int i = 0; i < n; i++) a[i] = i + 1;
            printf("Threads = %d\n", omp_get_num_threads());
        }

        #pragma omp for reduction(+:sum,even)
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (a[i] % 2 == 0) even++;
            #pragma omp atomic
            pSum += a[i];
        }

        #pragma omp critical
        printf("T%d PartialSum=%d\n", omp_get_thread_num(), pSum);

        #pragma omp master
        printf("Final Sum=%d  Even=%d\n", sum, even);
    }
    return 0;
}