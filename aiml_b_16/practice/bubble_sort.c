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
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j+1]<a[j]){
                int temp;
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
    }
    for(int i =0;i<n;i++){
        printf("%d \t",a[i]);
    }

}