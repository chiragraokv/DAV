#include <stdio.h>
#include <stdlib.h>
//POINTERS, RECURSION AND DYNAMIC MEMORY ALLOCATION FUNCTIONS
//Implement a C program to read, display, and find the product of two matrices using
//functions with appropriate parameters.
//• The matrices must be created using dynamic memory allocation (malloc or
//calloc).
//• Access matrix elements using array dereferencing (i.e., *(*(mat + i) + j)style).nction.
void display(int *a, int n){
    for(int i = 0;i<n;i++){
        printf("%d",*(a+i));
    }
    }
int man()
{
    int n,**arr,**arr_2;
 printf("enter the number shape of first square matrix \n");
 scanf("%d",&n);
 arr = (int *)malloc(n * sizeof(int));
 for(int i = 0;i<n;i++){
    *(arr+i) = (int *)malloc(n * sizeof(int));
 }
 printf("enter the elements of the first matrix");
 for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
        scanf("%d",*(*(arr+i)+j));
    }
 }

 arr_2 = (int *)malloc(n * sizeof(int));
 for(int i = 0;i<n;i++){
    *(arr_2+i) = (int *)malloc(n * sizeof(int));
 }
 printf("enter the elements of the first matrix");
 for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
        scanf("%d",&arr_2[i][j]);
    }
 }
return 0;
}

