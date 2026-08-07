// Implement a parallel OpenMP program to generate the histrogram of a given array. Compare the execution time of sequential and parallel implementations.
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100000000
#define BINS 10

int main() {
    printf("Name: Chirag Rao KV\n");
    printf("REG: 240962180\n");
    int *data = malloc(N * sizeof(int)), h1[BINS] = {0}, h2[BINS] = {0};
    for (int i = 0; i < N; i++) data[i] = rand() % 100;

    double t = omp_get_wtime();
    for (int i = 0; i < N; i++) h1[data[i] * BINS / 100]++;
    printf("Seq: %.4fs\n", omp_get_wtime() - t);

    t = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        #pragma omp atomic
        h2[data[i] * BINS / 100]++;
    }
    printf("Par: %.4fs\n", omp_get_wtime() - t);

    printf("Histogram: ");
    for (int i = 0; i < BINS; i++) printf("%d ", h2[i]);
    printf("\n");

    free(data);
    return 0;
}