#include <stdio.h>
#include <stdlib.h>
//POINTERS, RECURSION AND DYNAMIC MEMORY ALLOCATION FUNCTIONS
//Write a small function to find the smallest element in an array using pointers.
//In the main function, create a dynamically allocated array, read the values from the
//keyboard, and pass the array to the function.
//Display the result (smallest element) in the main function.
int Find_smallest(int *a,int n){
    int smallest = *a;
    for(int i = 0;i<n;i++){
        if(smallest >*(a+i)){
            smallest = *(a+i);
        }
    }
    return smallest;
}
int mun()
{
    int n,i,*arr;
    printf("enter the number of elements in the array \n");
    scanf("%d",&n);
    arr = (int *)malloc(n * sizeof(int));
    if(arr == NULL) {
        printf("Memory not allocated.\n");
        return 1;
        }
    printf("enter the elements \n");
    for(i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("smallest in array = %d",Find_smallest(arr,n));
return 0;
}
