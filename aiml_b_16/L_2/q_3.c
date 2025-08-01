#include <stdio.h>
#include <stdlib.h>
//POINTERS, RECURSION AND DYNAMIC MEMORY ALLOCATION FUNCTIONS
//Implement a C program to read, display, and find the product of two matrices using
//functions with appropriate parameters.
//• The matrices must be created using dynamic memory allocation (malloc or
//calloc).
//• Access matrix elements using array dereferencing (i.e., *(*(mat + i) + j)style).nction.
void display(int **a, int n){
    printf("\ndisplay \n");
    for(int i = 0;i<n;i++){
            for(int j=0;j<n;j++)
        printf("%d \t",*(*(a+i)+j));
        printf("\n");
    }

    }
void matrix_multiply(int **a, int **b,int n){
    int sum = 0,i,j,**mul;

    mul = (int *)malloc(n * sizeof(int));
     for(i = 0;i<n;i++){
        *(mul+i) = (int *)malloc(n * sizeof(int));
     }
    for(i = 0;i<n;i++){
        for(j=0;j<n;j++){
                for(int k = 0;k<n;k++){
            sum += (*(*(a+k)+j))*(*(*(b+j)+k));
                }
        mul[j][i] = sum;
        sum = 0;
        }

    }
    display(mul,n);
    return;
}
int man()
{
    int n,**arr,**arr_2;
 printf("enter the shape of first square matrix \n");
 scanf("%d",&n);
 arr = (int *)malloc(n * sizeof(int));
 for(int i = 0;i<n;i++){
    *(arr+i) = (int *)malloc(n * sizeof(int));
 }
 printf("enter the elements of the first matrix \n");
 for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
        scanf("%d",&arr[i][j]);
    }
 }

 arr_2 = (int *)malloc(n * sizeof(int));
 for(int i = 0;i<n;i++){
    *(arr_2+i) = (int *)malloc(n * sizeof(int));
 }
 printf("enter the elements of the second matrix");
 for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
        scanf("%d",&arr_2[i][j]);
    }
 }

matrix_multiply(arr,arr_2,n);

return 0;
}


