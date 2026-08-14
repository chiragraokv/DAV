//Implement a program in MPI wher every ranked process prints factorial of the rank 
// and odd ranked process prints ranks Fibonacci series
#include <mpi.h>
#include <stdio.h>

long long factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

long long fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main(int argc, char** argv) {
    
    int rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if(rank == 0){
        printf("Chirag Rao KV\n");
        printf("240962180\n");
    }
    printf("p %d: Fact(%d) = %lld\n", rank, rank, factorial(rank));
    if (rank % 2 != 0) {
        printf("p %d : Fibo(%d) = %lld\n", rank, rank, fibonacci(rank));
    }

    MPI_Finalize();
    return 0;
}