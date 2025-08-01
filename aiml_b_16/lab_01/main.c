#include <stdio.h>
#include <stdlib.h>
// Given an array of n integers and a key element, write a C program to search the element
//using linear search.

int main()
{
    int n = 5,search,flag = 0;
    int array[5] = {1,8,6,6,5};
    printf("input the number to search for :");
    scanf("%d",&search);
    for(int i = 0;i<n;i++){
        if(array[i] == search){
            printf("\n%d found in position %d",search,i+1);
            flag ++;
        }
    }
    if(flag == 0){
        printf("%d not found",search);
    }
    return 0;
}
