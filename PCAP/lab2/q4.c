// impliment an OpenMp program to perform matrix-vector multiplication. record the effect of increasing matrix size on execution time
#include <stdio.h>
#include <omp.h>

int main(){
    int n;
    printf("Name: Chirag Rao KV\n");
    printf("REG: 240962180\n");
    scanf("%d",&n);
    int A[n][n],x[n],y[n];

    for(int i=0;i<n;i++){
        x[i]=1;
        for(int j=0;j<n;j++) 
        A[i][j]=i*10+j;
    }

    double t=omp_get_wtime();

    #pragma omp parallel for
    for(int i=0;i<n;i++){
        y[i]=0;
        for(int j=0;j<n;j++)
            y[i]+=A[i][j]*x[j];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d\t",y[i]);
        printf("\n");
    }

    printf("Time: %lf sec\n",omp_get_wtime()-t);
}