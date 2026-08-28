// Implement a MPI program using N processes to find 1!+2!+...+N!,
// use scan. Also handle different errors using error handling routines.
#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, n, fact = 1, sum, err;
    char msg[MPI_MAX_ERROR_STRING];
    int len;

    MPI_Init(&argc, &argv);
    MPI_Comm_set_errhandler(MPI_COMM_WORLD, MPI_ERRORS_RETURN);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &n);

    for (int i = 1; i <= rank + 1; i++)
        fact *= i;

    err = MPI_Scan(&fact, &sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    if (err != MPI_SUCCESS) {
        MPI_Error_string(err, msg, &len);
        printf("Error: %s\n", msg);
    }

    if (rank == n - 1)
        printf("Sum = %d\n", sum);
    if (rank == 0){
        printf("Chirag Rao KV\n");
        printf("240962180\n");
    }

    MPI_Finalize();
    return 0;
}
