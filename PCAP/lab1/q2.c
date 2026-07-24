// Implement an OpenMP program that creates a user-specified number of threads using the
// omp_set_num_threads() runtime function and displays the Thread ID of each thread.

#include <stdio.h>
#include <omp.h>

void parallel_function(int no_threads) 
{
    #pragma omp parallel num_threads(no_threads)
    {
        printf("thread: %d/%d\n", omp_get_thread_num(), omp_get_num_threads());
    }
}

int main() 
{
    int no;
    printf("Enter number of threads: "); 
    if (scanf("%d", &no) == 1) {
        parallel_function(no);
    }
    return 0;
}
