// Implement a parallel OpenMP program to estimate the value of Pi using Monte Carlo technique

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define NUM_POINTS 100000000

int main() {
    long inside_count = 0;
    double t = omp_get_wtime();
    printf("Name: Chirag Rao KV\n");
    printf("REG: 240962180\n");
    #pragma omp parallel reduction(+:inside_count)
    {
        unsigned int seed = 42 + omp_get_thread_num();
        #pragma omp for
        for (long i = 0; i < NUM_POINTS; i++) {
            double x = (double)rand_r(&seed) / RAND_MAX;
            double y = (double)rand_r(&seed) / RAND_MAX;
            if (x * x + y * y <= 1.0) {
                inside_count++;
            }
        }
    }

    double pi = 4.0 * inside_count / NUM_POINTS;
    printf("Estimated Pi: %.6f | Time: %.4fs\n", pi, omp_get_wtime() - t);
    
    return 0;
}