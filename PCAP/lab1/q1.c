// Implement an OpenMP program to determine and display the total number of threads
// participating in a parallel region using the omp_get_num_threads() runtime function.
#include<stdio.h>
#include<omp.h>
int main()
{
#pragma omp parallel
{
    int total = omp_get_num_threads();
    printf(" total threads: %d", total);
}
return 0;
}