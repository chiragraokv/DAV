// Implement a MPI program to read two strings S1 and S2 of same length in the root process. 
// Using N procersses inclusing the root ( string length is evenly divisible by N), procude the 
// resultant string as shown below. Display the resultant string in the root process . Use collective Communication routines.
// s1: string s2: length resultant string: slternigntgh

#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, N, len, i;
    char s1[100], s2[100], r1[100], r2[100], result[200];
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &N);
    if (rank == 0) {
        strcpy(s1, "string");
        strcpy(s2, "length");
        len = strlen(s1);
    }
    MPI_Bcast(&len, 1, MPI_INT, 0, MPI_COMM_WORLD);
    int m = len / N;
    char a[m], b[m], c[2 * m];
    MPI_Scatter(s1, m, MPI_CHAR, a, m, MPI_CHAR, 0, MPI_COMM_WORLD);
    MPI_Scatter(s2, m, MPI_CHAR, b, m, MPI_CHAR, 0, MPI_COMM_WORLD);
    for (i = 0; i < m; i++) {
        c[2*i] = a[i];
        c[2*i+1] = b[i];
    }
    MPI_Gather(c, 2*m, MPI_CHAR, result, 2*m, MPI_CHAR, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        printf("Chirag Rao KV\n");
        printf("240962180\n");
        result[2*len] = '\0';
        printf("%s\n", result);
    }
    MPI_Finalize();
    return 0;
}
