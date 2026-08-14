// Implement a MPI program to read N elements of an array in the master process. 
// Let N processes including master process check the array values are prime or not.
#include <mpi.h>
#include <stdio.h>

int is_prime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int main(int argc, char** argv) {
    int r, val;
    int a[] = {2, 4, 5, 11, 15, 17, 19, 22}; // Sample array

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &r);
     if (!r) {
        printf("Chirag Rao KV\n");
        printf("240962180\n");  }
    MPI_Scatter(a, 1, MPI_INT, &val, 1, MPI_INT, 0, MPI_COMM_WORLD);

    printf("Process %d: %d is %s\n", r, val, is_prime(val) ? "Prime" : "Not Prime");

    MPI_Finalize();
}