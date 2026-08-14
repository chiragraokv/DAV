// Implement a MPO programme  to read an integer valuei the root process. 
// Root process sends this value to Process1. Process 1 sends this value t Process 2 and so on. 
// Last Process sends the value back to root process. When sending the value each process will 
// first increment the recieved value by 1. Implement the program using point to point 
// communication.
#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int r, size, v = 0;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &r);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (!r) {
        printf("Chirag Rao KV\n");
        printf("240962180\n");  
        MPI_Send(&v, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(&v, 1, MPI_INT, size - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Final: %d\n", v);
    } else {
        MPI_Recv(&v, 1, MPI_INT, r - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("hop from %d: %d\n",r, v+1);
        v++;
        MPI_Send(&v, 1, MPI_INT, (r + 1) % size, 0, MPI_COMM_WORLD);
    }
    MPI_Finalize();
}