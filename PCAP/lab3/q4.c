// Write a parallel program using OpenMP to implement the Merge Sort algorithm.
// Analyze the performence by computing
// Sequential execution time
// Parallel execution Time
// Speedup
// Efficiency
// for varying imnput size and thread counts
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void merge(int a[],int l,int m,int r){
    int i=l,j=m+1,k=0,t[r-l+1];
    while(i<=m&&j<=r) t[k++]=a[i]<a[j]?a[i++]:a[j++];
    while(i<=m) t[k++]=a[i++];
    while(j<=r) t[k++]=a[j++];
    for(i=l,k=0;i<=r;i++) a[i]=t[k++];
}

void msort(int a[],int l,int r){
    if(l>=r) return;
    int m=(l+r)/2;
    msort(a,l,m);
    msort(a,m+1,r);
    merge(a,l,m,r);
}

void pmsort(int a[],int l,int r,int d){
    if(l>=r) return;
    int m=(l+r)/2;
    if(d>0){
        #pragma omp task
        pmsort(a,l,m,d-1);
        #pragma omp task
        pmsort(a,m+1,r,d-1);
        #pragma omp taskwait
    }else{
        msort(a,l,m);
        msort(a,m+1,r);
    }
    merge(a,l,m,r);
}

int main(){
    printf("Name: Chirag Rao KV\n");
    printf("REG: 240962180\n");
    int n=100000,*a=malloc(n*sizeof(int)),*b=malloc(n*sizeof(int));
    for(int i=0;i<n;i++) a[i]=b[i]=rand();

    double t1=omp_get_wtime();
    msort(a,0,n-1);
    t1=omp_get_wtime()-t1;

    double t2=omp_get_wtime();
    #pragma omp parallel
    {
        #pragma omp single
        pmsort(b,0,n-1,4);
    }
    t2=omp_get_wtime()-t2;

    int th=omp_get_max_threads();
    printf("Seq=%f\nPar=%f\nSpeedup=%f\nEfficiency=%f\n",
           t1,t2,t1/t2,(t1/t2)/th);

    free(a); free(b);
    return 0;
}