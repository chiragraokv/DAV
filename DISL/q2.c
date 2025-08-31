#include <stdio.h>
#include <stdlib.h>
// Given an array of integers, implement binary search to find the position of a given key.

int main()
{
    int n = 5,search,flag = 0;
    int mid,end,start;
    int array[5] = {10,22,23,64,85};
    printf("Binary search\n");
    printf("input the number to search for :");
    scanf("%d",&search);
    start = 0;
    end = n-1;
    mid = (end+start)/2;
    while(end>start){
        mid = (start+end)/2;
       if(array[mid]<search){
        start = mid;
       }
        else{
            end = mid;
        }
        if(array[mid] == search){
            printf("Found %d at %d",search,mid+1);
            flag++;
            break;
        }
       }
       if(flag == 0){
        printf("%d element not found",search);
       }

    return 0;
}
