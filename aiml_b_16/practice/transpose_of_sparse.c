#include<stdio.h>
#include<stdlib.h>
typedef struct  sparse
{
    int data;
    int row;
    int col;
};

void fast_transpose(struct sparse a[],struct sparse b[]){
    int n = a[0].data;
    int col = a[0].col;
    int current =0;
    b[0].col = a[0].row;
    b[0].row = a[0].col;
    b[0].data = a[0].data;
    int element_row[col];
    for(int i = 0;i<col;i++){
        element_row[i] = 0;

    }
    for(int i =1;i<=n;i++){
        element_row[a[i].col]++;
    }
    int start[col];
    start[0] = 1;

    // compute starting pos
    for(int j =1;j<col;j++){
        start[j] = start[j-1]+element_row[j-1];// the starting pos of first element of that row is start of prev + no of elements of prev 
    }

    for(int i =1;i<=col;i++){
        int j = start[a[i].col]++;
        b[j].col = a[i].row;
        b[j].row = a[i].col;
        b[j].data = a[i].data;
    }

}

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