#include <stdio.h>
#include <omp.h>

#define M 4 // Number of rows
#define N 5 // Number of columns

int main() {
    int A[M][N], B[M][N], C[M][N];
    int row_threads[M]; 

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = (i + 1) * 10 + j;
            B[i][j] = (i + j);          
    }
}

    #pragma omp parallel for shared(A, B, C, row_threads) schedule(static)
    for (int i = 0; i < M; i++) {
        row_threads[i] = omp_get_thread_num();

        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    
    for (int i = 0; i < M; i++) {
        printf("Row %d: [ ", i);
        for (int j = 0; j < N; j++) {
            printf("%3d ", C[i][j]);
        }
        printf("]  <- Computed by Thread ID: %d\n", row_threads[i]);
    }

    return 0;
}
