// Implement a program in MPI to toggle the character of a given starting indexed by the rank of 
// the process. Hint: Suppose the string is HELLO and there are 5 processes 0 to toggle H to h and 
// process 1 to toggle E to e and so on.
#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int rank;
    printf("Chirag Rao KV\n");
    printf("240962180\n");
    char s[6] = "MaNiPaL", c;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Bcast(s, 6, MPI_CHAR, 0, MPI_COMM_WORLD);
    c = s[rank] ^ 32;
    printf("Process %d toggled '%c' to '%c'\n", rank, s[rank], c);
    MPI_Gather(&c, 1, MPI_CHAR, s, 1, MPI_CHAR, 0, MPI_COMM_WORLD);
    if (!rank) printf("Final String: %s\n", s);
    MPI_Finalize();
}