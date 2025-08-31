
#include<stdio.h>
#include<stdlib.h>
struct emp{
    int id;
    char name[50];
    float sal;
}emp;
void enter_data(struct emp* e, int n){
    for(int i = 0;i<n;i++){
        float sal;
        int id;
        char name[50];
        printf("enter id, \n");
        scanf("%d",&id);
         printf("enter salary\n");
        scanf("%f",&sal);
        (e+i)->id = id;
        (e+i)->sal = sal;
    }
}
void display_data(struct emp* e, int n){
    for(int i = 0;i<n;i++){
        printf("id %d, salary %f\n",(e+i)->id,(e+i)->sal);
    }
}
int main(){
    printf("enter the number of students\n");
    int n;
    scanf("%d",&n);
    struct emp e[n];
    enter_data(e,n);
    display_data(e,n);
}
