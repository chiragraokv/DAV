//Implement an OpenMP program to compute the sum of the first N natural numbers in parallel. Using the same program, demonstratge the effect of the following OpenMp data-sharing clauses:
// shared
// Private
// first Private
// lastprivate
// For each case:
// Execute a program
// Observe the output produced
// Explain the effect of the data sharing clause on:
//     variable values
//     data accessability among threads
//     corectness of the final result

#include <stdio.h>
#include <omp.h>

int main() {
    int N = 10;
    int sum = 0;
    int x = 5, y = 0;
    printf("Name: Chirag Rao KV\n");
    printf("REG: 240962180\n");
    #pragma omp parallel for shared(sum)
    for(int i = 1; i <= N; i++) {
        #pragma omp atomic
        sum += i;
    }
    printf("Shared: sum = %d\n", sum);

    // private
    x = 5;
    #pragma omp parallel private(x)
    {
        x = omp_get_thread_num();
    }
    printf("Private: x = %d\n", x);

    // firstprivate
    x = 5;
    #pragma omp parallel firstprivate(x)
    {
        x += omp_get_thread_num();
    }
    printf("Firstprivate: x = %d\n", x);

    // lastprivate
    y = 0;
    #pragma omp parallel for lastprivate(y)
    for(int i = 1; i <= N; i++) {
        y = i;
    }
    printf("Lastprivate: y = %d\n", y);

    return 0;
}