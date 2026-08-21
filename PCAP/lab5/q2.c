// Implement a MPI program to read an integer value M and NXM elements into 
// an 1d array in the root process, where N is the number of processes. 
// Root process sends M elements toeach process. Each process finds average 
// of M elements it recieved and sends the average value to root. Root collects
// all the values and finds the total average. Use collective communication routines.
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, N, M, i, a[100], local[100];
    float avg, total;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &N);
    if (rank == 0) {
        M = 4;  
        printf("Chirag Rao KV\n");
        printf("240962180\n");
        for (i = 0; i < N * M; i++)
            a[i] = rand() % 10 + 1;
    }
    MPI_Bcast(&M, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(a, M, MPI_INT, local, M, MPI_INT, 0, MPI_COMM_WORLD);
    avg = 0;
    for (i = 0; i < M; i++)
        avg += local[i];
    avg /= M;
    MPI_Reduce(&avg, &total, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0)
        printf("Total average = %.2f\n", total / N);

    MPI_Finalize();
    return 0;
}
