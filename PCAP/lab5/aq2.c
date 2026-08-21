// Impelement a MPI program using collective communiucaton functions to replace all 
// even elements of array A to 1 and replace all odd element to 0 of size N.
// Displa the resultant array A, count of all even and odd numbers in root process.
//  Assume N is evenly divisible by number of processes.
#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv) {
    int r, p, N = 8, A[8] = {2, 5, 8, 7, 4, 9, 6, 3};
    int B[8], even, odd, te, to;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &r);
    MPI_Comm_size(MPI_COMM_WORLD, &p);

    int m = N / p, local[m];

    MPI_Scatter(A, m, MPI_INT, local, m, MPI_INT, 0, MPI_COMM_WORLD);

    even = odd = 0;
    for (int i = 0; i < m; i++) {
        if (local[i] % 2 == 0) {
            local[i] = 1;
            even++;
        } else {
            local[i] = 0;
            odd++;
        }
    }

    MPI_Gather(local, m, MPI_INT, B, m, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Reduce(&even, &te, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&odd, &to, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (!r) {
        printf("Chirag Rao KV\n");
        printf("240962180\n");
        for (int i = 0; i < N; i++) printf("%d ", B[i]);
        printf("\nEven = %d Odd = %d\n", te, to);
    }

    MPI_Finalize();
}
