// Implement an OpenMP program to read a matrix of size 5x5 and produce matrix B 
// according to the specified transformation
// * Principal Diognal = 0
// * Elements below the diognal = max value of the corresponsing row in A 
// * elements above the dionganl = min value of the corresponding row in A

#include <stdio.h>
#include <omp.h>

int main() {
    int A[5][5], B[5][5];
    printf("Name: Chirag Rao KV\n");
    printf("REG: 240962180\n");
    printf("Enter 5x5 matrix:\n");
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            scanf("%d",&A[i][j]);

    #pragma omp parallel for
    for(int i=0;i<5;i++) {
        int max=A[i][0], min=A[i][0];
        for(int j=1;j<5;j++) {
            if(A[i][j]>max) max=A[i][j];
            if(A[i][j]<min) min=A[i][j];
        }
        for(int j=0;j<5;j++) {
            if(i==j) B[i][j]=0;
            else if(i>j) B[i][j]=max;
            else B[i][j]=min;
        }
    }

    printf("\nMatrix B:\n");
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++)
            printf("%4d",B[i][j]);
        printf("\n");
    }
    return 0;
}