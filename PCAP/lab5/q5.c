// Implement parallel selection sort[hint: use merge sort after sorting subarrays using parallel selection sort]

#include <stdio.h>
#include <mpi.h>

void sort(int *a,int n){
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(a[i]>a[j]){int t=a[i];a[i]=a[j];a[j]=t;}
}

void merge(int *a,int n){
    int t[100],i=0,j=n/2,k=0;
    while(i<n/2&&j<n)t[k++]=(a[i]<a[j])?a[i++]:a[j++];
    while(i<n/2)t[k++]=a[i++];
    while(j<n)t[k++]=a[j++];
    for(i=0;i<n;i++)a[i]=t[i];
}

int main(int c,char **v){
    int r,p,a[100]={64,25,12,22,11,90,34,7},b[100],n=8;

    MPI_Init(&c,&v);
    MPI_Comm_rank(MPI_COMM_WORLD,&r);
    MPI_Comm_size(MPI_COMM_WORLD,&p);

    int m=n/p;
    MPI_Scatter(a,m,MPI_INT,b,m,MPI_INT,0,MPI_COMM_WORLD);
    sort(b,m);
    MPI_Gather(b,m,MPI_INT,a,m,MPI_INT,0,MPI_COMM_WORLD);

    if(!r){
        printf("Chirag Rao KV\n");
        printf("240962180\n");
        for(int s=m;s<n;s*=2)
            for(int i=0;i<n;i+=2*s)
                if(i+s<n) merge(a+i,(i+2*s<n)?2*s:n-i);

        for(int i=0;i<n;i++) printf("%d ",a[i]);
    }

    MPI_Finalize();
}
