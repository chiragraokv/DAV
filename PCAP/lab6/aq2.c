// Implement a MPI program to read matrix A of size 5x. It produces a resultant matrix B. It sets all principle diognal elements of B to 0
// It replaces each row elements in the B matrix in the following manner. IF the element is below the principle diognal 
// it replaces it with the maximumof the column in th ematrix A having the same row number of B. Produce
// the B matrix using 5 processes. Use only collective communication routines except brodcast routine.
#include <stdio.h>
#include <mpi.h>

int main(int argc,char **argv)
{
    int r,A[5][5],B[5][5],mx[5];

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&r);

    if(r==0)
        for(int i=0;i<5;i++)
            for(int j=0;j<5;j++)
                scanf("%d",&A[i][j]);

    MPI_Bcast(A,25,MPI_INT,0,MPI_COMM_WORLD);

    for(int j=0;j<5;j++)
        mx[j]=A[0][j];

    for(int i=1;i<5;i++)
        for(int j=0;j<5;j++)
            if(A[i][j]>mx[j])
                mx[j]=A[i][j];

    for(int j=0;j<5;j++)
    {
        if(j==r)
            B[r][j]=0;
        else if(j<r)
            B[r][j]=mx[r];
        else
            B[r][j]=A[r][j];
    }

    if(r==0)
        MPI_Gather(MPI_IN_PLACE,5,MPI_INT,B,5,MPI_INT,0,MPI_COMM_WORLD);
    else
        MPI_Gather(B[r],5,MPI_INT,B,5,MPI_INT,0,MPI_COMM_WORLD);

    if(r==0)
        for(int i=0;i<5;i++)
            printf("%d %d %d %d %d\n",
                   B[i][0],B[i][1],B[i][2],B[i][3],B[i][4]);

    MPI_Finalize();
    return 0;
}
