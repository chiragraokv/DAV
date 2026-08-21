// Implement a MPI program to read a value M and Nxm numbe of elements into 1D array
//  where N is the total number of process. Find the square of first M numbers 
// the cube of next M numbers and so on.
// Print the results in the root.
#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv) {
    int r, p, M = 2, a[100], b[100];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &r);
    MPI_Comm_size(MPI_COMM_WORLD, &p);

    if (!r)
        for (int i = 0; i < p * M; i++) a[i] = i + 1;

    MPI_Scatter(a, M, MPI_INT, b, M, MPI_INT, 0, MPI_COMM_WORLD);

    int power = r + 2;
    for (int i = 0; i < M; i++) {
        int x = 1;
        for (int j = 0; j < power; j++) x *= b[i];
        b[i] = x;
    }

    MPI_Gather(b, M, MPI_INT, a, M, MPI_INT, 0, MPI_COMM_WORLD);

    if (!r) {
         printf("Chirag Rao KV\n");
        printf("240962180\n");
        for (int i = 0; i < p * M; i++) printf("%d ", a[i]);
        printf("\n");
    }

    MPI_Finalize();
}
