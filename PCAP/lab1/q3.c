// 3. Implement an OpenMP program to initialize all elements of a 5 × 5 matrix with consecutive
// integers inside a parallel region using the parallel directive. Display the initialized matrix
// and print the Thread ID responsible for initializing each row.

#include <stdio.h>
#include <omp.h>

#define SIZE 5

int main() {
    int matrix[SIZE][SIZE];
    int row_threads[SIZE]; 

   
    #pragma omp parallel shared(matrix, row_threads)
    {
        #pragma omp for schedule(static)
        for (int i = 0; i < SIZE; i++) {
            row_threads[i] = omp_get_thread_num();

            for (int j = 0; j < SIZE; j++) {
                matrix[i][j] = (i * SIZE) + j + 1;
            }
        }
    } 

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("  by Thread ID: %d\n", row_threads[i]);
    }

    return 0;
}
