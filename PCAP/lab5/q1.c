//Implement a MPI program to read N values in the root process.
//  Root process sends one value to each process . Everyh process receives it
// and finds the factorial of that number and returns it to the root. 
// Root process gathers the factorial and finds the sum of it. Use N number of processes.
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
long long fact(int n) {
    long long f = 1;
    for (int i = 1; i <= n; i++) f *= i;
    return f;
}
int main(int argc, char *argv[]) {
    int rank, size, x, a[100];
    long long f, sum;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0) {
            printf("Chirag Rao KV\n");
            printf("240962180\n");
        srand(1);
        for (int i = 0; i < size; i++)
            a[i] = rand() % 10 + 1;
    }
    MPI_Scatter(a, 1, MPI_INT, &x, 1, MPI_INT, 0, MPI_COMM_WORLD);
    f = fact(x);
    Reduce(&f, &sum, 1, MPI_LONG_LONG, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0)
        printf("Sum of factorials = %lld\n", sum);
    MPI_Finalize();
    return 0;
}
