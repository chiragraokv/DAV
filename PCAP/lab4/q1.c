// Implement a simple MPI program to find out pow(x,rank) for all 
// the processes where x  is the integer constant and the rank is the rank of the process

#include <stdio.h>
#include <mpi.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int rank, size;
    const int x = 2;
    double result;
    printf("Chirag Rao KV\n");
    printf("240962180\n");
    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    result = pow(x, rank);

    printf("Process %d: %d^%d = %.0f\n", rank, x, rank, result);

    MPI_Finalize();

    return 0;
}