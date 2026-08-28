// Implement a MPI program to read a word of length N. Using N processes including the root get outyput word with the pattern as shown in example. Display the resultant output word in root.
// input: PCAP
// OUTPUT: PCCAAPPP

#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc,char **argv)
{
    int r,n;
    char w[100],c;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&r);
    MPI_Comm_size(MPI_COMM_WORLD,&n);

    if(r==0)
    {
        printf("Chirag Rao K V\n240962180\nEnter string\t");
        scanf("%s",w);
        n=strlen(w);
    }

    MPI_Bcast(&n,1,MPI_INT,0,MPI_COMM_WORLD);
    MPI_Scatter(w,1,MPI_CHAR,&c,1,MPI_CHAR,0,MPI_COMM_WORLD);

    if(r==0)
    {

        printf("%c",c);
        for(int i=1;i<n;i++)
        {
            MPI_Recv(&c,1,MPI_CHAR,i,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
            for(int j=0;j<i+1;j++) printf("%c",c);
        }
        printf("\n");
    }
    else
        MPI_Send(&c,1,MPI_CHAR,0,0,MPI_COMM_WORLD);

    MPI_Finalize();
    return 0;
}
