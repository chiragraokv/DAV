// Implement a program in MPI to reverse the digits of the following integer array of size 9 with 9 processes. Initialize the aray to the following values.
// input array: 18. 523, 301 ,1234, 2, 14, 108, 150, 1928
// output array: 81, 325, 103, 4321, 2 , 41, 801, 51, 8291
#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int r, x, rev;
    int in[9] = {18, 523, 301, 1234, 2, 14, 108, 150, 1928};
    int out[9];

        printf("Chirag Rao KV\n");
        printf("240962180\n");  
     if (!r) {
        printf("Chirag Rao KV\n");
        printf("240962180\n");  
     }
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &r);

    MPI_Scatter(in, 1, MPI_INT, &x, 1, MPI_INT, 0, MPI_COMM_WORLD);

    for (rev = 0; x > 0; x /= 10) 
        rev = rev * 10 + x % 10;

    MPI_Gather(&rev, 1, MPI_INT, out, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (!r) {
        printf("Output Array: ");
        for (int i = 0; i < 9; i++) printf("%d ", out[i]);
        printf("\n");
    }
    MPI_Finalize();
}