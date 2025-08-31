#include <stdio.h>
#include <stdlib.h>
// Write a C program to sort a given list of elements using
//Bubble Sort
//Selection Sort
//Insertion Sort
int main()
{
    int n = 5,search,c;
    int array[5] = {1,8,6,7,5};
    int small = array[0];
    //bubble sort
    for(int i = 0;i<n-1;i++){
            for(int j= 0;j<n-1;j++){
                    if(array[j]>array[j+1]){
                        c = array[j];
                        array[j] = array[j+1];
                        array[j+1] = c;
                    }
            }
        }
    //print the output of bubble sort
    printf("bubble sort output\n");
    for(int i = 0;i<5;i++){
        printf("%d,",array[i]);
    }
    printf("\n\n");
    //selection sort
    int pos,temp,j;
    int a[5] = {1,8,6,7,5};
    for(int i = 0;i<n-1;i++){
            small = a[i];
            pos = i;
            for( j= 0;j<n-i;j++){
                    if(small>a[j+i]){
                        pos = j+i;
                    }
            }
            temp = a[i];
            a[i] = a[pos];
            a[pos] = temp;
        }
    //print the values of selection sort
    printf("selection sort output\n");
    for(int i = 0;i<n;i++){
        printf("%d,",a[i]);
    }
    //insertion sort
    for(int i = 0;i<n;i++){
            small = a[i];
        for(j = i;j>=0;j--){
            if(a[j]<small){
                pos = j;

            }

        }
    }


    return 0;
}
