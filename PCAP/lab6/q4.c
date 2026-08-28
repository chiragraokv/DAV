//Implement parallel odd even transposition sort
#include <stdio.h>
#include <mpi.h>

int main(int argc,char **argv)
{
    int r,p,n=8,a[8]={8,3,7,4,2,6,1,5},x,y;
    
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&r);
    MPI_Comm_size(MPI_COMM_WORLD,&p);

    x=a[r];
    if(r==0)
    {
        printf("Chirag Rao K V\n240962180\nBefore soritng:\n");
        for(int i=0;i<p;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    for(int i=0;i<p;i++)
    {
        if((i+r)%2==0 && r<p-1)
        {
            MPI_Sendrecv(&x,1,MPI_INT,r+1,0,&y,1,MPI_INT,r+1,0,
                         MPI_COMM_WORLD,MPI_STATUS_IGNORE);
            if(x>y) x=y;
        }
        else if((i+r)%2==1 && r>0)
        {
            MPI_Sendrecv(&x,1,MPI_INT,r-1,0,&y,1,MPI_INT,r-1,0,
                         MPI_COMM_WORLD,MPI_STATUS_IGNORE);
            if(x<y) x=y;
        }
    }

    MPI_Gather(&x,1,MPI_INT,a,1,MPI_INT,0,MPI_COMM_WORLD);

    if(r==0)
    {
        printf("after soritng\n");
        for(int i=0;i<p;i++)
            printf("%d ",a[i]);
        printf("\n");
    }

    MPI_Finalize();
    return 0;
}
