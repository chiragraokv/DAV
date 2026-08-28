// implement a MPi program to read a 3x3 matrix.  enter an e3lement to be searched in the root process. 
// Find the number of occurences of this element in the matrix using three processes
#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, size;
    int matrix[3][3], row[3];
    int element, local_count = 0, total_count = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size != 3)
    {
        MPI_Finalize();
        return 0;
    }

    if (rank == 0)
    {
        printf("Chirag Rao K V\n240962180\n");
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                scanf("%d", &matrix[i][j]);
        printf("element to count:\t");
        scanf("%d", &element);
    }

    MPI_Bcast(&element, 1, MPI_INT, 0, MPI_COMM_WORLD);

    MPI_Scatter(matrix, 3, MPI_INT,
                row, 3, MPI_INT,
                0, MPI_COMM_WORLD);

    for (int i = 0; i < 3; i++)
        if (row[i] == element)
            local_count++;

    MPI_Reduce(&local_count, &total_count, 1,
               MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
        printf(" total count:%d\n", total_count);

    MPI_Finalize();
    return 0;
}
