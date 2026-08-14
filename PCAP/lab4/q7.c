// Implement a MPI program to read N elements of the aray in the root process where N is equal 
// to total number of processes. The root process sends one value to each of the slaves. 
// Let even ranked process find square of the recieved number and odd ranked process find
//  the cube of recieved element. Use Buffer send.
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int r, size, v, a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int buf_size = 100;
    void *buf = malloc(buf_size);

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &r);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Buffer_attach(buf, buf_size);

    if (!r) {
        printf("Chirag Rao KV\n");
        printf("240962180\n");  
        for (int i = 0; i < size; i++) 
            MPI_Bsend(&a[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
    }

    MPI_Recv(&v, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    v = (r % 2 == 0) ? v * v : v * v * v;
    printf("Process %d: %d\n", r, v);

    MPI_Buffer_detach(&buf, &buf_size);
    MPI_Finalize();
    free(buf);
}