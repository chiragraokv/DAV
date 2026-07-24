#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100000000 
int main() {
    int *array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (long int i = 0; i < N; i++) {
        array[i] = 1; 
    }

    double start_time, end_time;
    double serial_time, parallel_time;
    long long serial_sum = 0;
    long long parallel_sum = 0;
    start_time = omp_get_wtime(); 
    
    for (long int i = 0; i < N; i++) {
        serial_sum += array[i];
    }
    
    end_time = omp_get_wtime();
    serial_time = end_time - start_time;
    start_time = omp_get_wtime(); 
    for (long int i = 0; i < N; i++) {
        parallel_sum += array[i];
    }
    
    end_time = omp_get_wtime();
    parallel_time = end_time - start_time;

    
    printf("Serial Implementation:\n");
    printf("  Calculated Sum : %lld\n", serial_sum);
    printf("  Execution Time : %.6f seconds\n\n", serial_time);
    
    printf("Parallel Implementation:\n");
    printf("  Calculated Sum : %lld\n", parallel_sum);
    printf("  Execution Time : %.6f seconds\n\n", parallel_time);
    
    printf("Performance Summary:\n");
    if (parallel_time < serial_time) {
        printf("  Parallel execution was %.2fx faster than serial execution.\n", 
               serial_time / parallel_time);
    } else {
        printf("  Serial execution was faster. (Try increasing array size N or check thread limits).\n");
    }

    // Clean up heap memory
    free(array);
    return 0;
}
