//Implement a MPI programme where the master process sends a number to 
// each of the slave and slave processes receives the number and prints it. Use standart send.

#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int r, size, n;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &r);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (!r) {
        printf("Chirag Rao KV\n");
        printf("240962180\n");   
        for (int i = 1; i < size; i++) {
            n = i * 10;
            MPI_Send(&n, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
    } else {
        MPI_Recv(&n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process %d received: %d\n", r, n);
    }
    MPI_Finalize();
}