// Implement a MPI program to read 4x4 matrix and display the following output
// ip = [[1,2,3,4],[1,2,3,1],[1,1,1,1],[2,1,2,1]]
// output = [[1,2,3,4],[2,4,6,5],[3,5,7,6],[5,6,9,7]]
#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    int r, a[4][4], row[4], sum[4];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &r);

    if (r == 0)
    {
        printf("Chirag Rao KV\n240962180\n");
        for (int i=0;i<4;i++)
            for (int j=0;j<4;j++)
                scanf("%d",&a[i][j]);
        }

    MPI_Scatter(a,4,MPI_INT,row,4,MPI_INT,0,MPI_COMM_WORLD);

    for (int j=0;j<4;j++)
        sum[j]=row[j];

    if (r>0)
    {
        MPI_Recv(row,4,MPI_INT,r-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

        for (int j=0;j<4;j++)
            sum[j]+=row[j];
    }

    if (r<3)
        MPI_Send(sum,4,MPI_INT,r+1,0,MPI_COMM_WORLD);

    MPI_Gather(sum,4,MPI_INT,a,4,MPI_INT,0,MPI_COMM_WORLD);

    if (r==0)
    {
        printf("OUTPUT\n");
        for (int i=0;i<4;i++)
            printf("%d %d %d %d\n",a[i][0],a[i][1],a[i][2],a[i][3]);
        }

    MPI_Finalize();
    return 0;
}
