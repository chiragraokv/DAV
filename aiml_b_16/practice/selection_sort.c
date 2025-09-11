#include<stdio.h>
#include<stdlib.h>
void main(){
    // impliment bubble sort
    int n;
    printf("enter the no of elements");
    scanf("%d",&n);
    int a[n];
    for(int i =0;i<n;i++){
    scanf("%d",&a[i]);
    }
    for(int i = 0;i<n;i++){
        int min = a[i],ind = i;
        for(int j = i+1;j<n;j++){
            if(min > a[j] ){
                ind = j;
                min = a[j];
            }
        }

        int temp = a[ind];
        a[ind] = a[i];
        a[i] = temp;
    }
    for(int i =0;i<n;i++){
        printf("%d \t",a[i]);
    }

}