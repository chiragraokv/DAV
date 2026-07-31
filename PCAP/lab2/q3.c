// Implement an OpenMp program that reads a matrix of size  M x N and produces
// matrix B where all the non border elements are replaced by their 1s compliment
// matrix D as specified
// D=
// 1 2 3 4
// 6 2 7 3
// 2 3 5 1 
// 9 1 2 5
#include <stdio.h>
#include <omp.h>

int B[20][20];

int main() {
    int A[20][20], m, n;
    printf("Name: Chirag Rao KV\n");
    printf("REG: 240962180\n");
    scanf("%d%d",&m,&n);

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&A[i][j]);

    // Compute B in parallel
    #pragma omp parallel for
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(i==0||j==0||i==m-1||j==n-1)
                B[i][j]=A[i][j];
            else
                B[i][j]=~A[i][j];   // 1's complement

    // Print B in order
    printf("\nMatrix B:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0||j==0||i==m-1||j==n-1)
                printf("%4d ",B[i][j]);
            else
                for(int k=3;k>=0;k--)
                    printf("%d",((B[i][j]>>k)&1));
            printf(" ");
        }
        printf("\n");
    }
    printf("\nMatrix D:\n");
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(i==0||j==0||i==m-1||j==n-1)
            printf("%4d",A[i][j]);
        else
            printf("%4d",(~A[i][j])&15);   // decimal value of 4-bit 1's complement
    }
    printf("\n");
}
}