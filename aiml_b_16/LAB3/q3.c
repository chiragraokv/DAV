//Define a structure Student with the following members:
//char name [50] – to store student name as a string
//int roll_no – to store roll number
//float marks – to store marks
//Write a C program that:
//i. Reads the details of ‘n’ students using a function that uses pointer to structure
//as an argument.
//ii. Displays the details of all students using a separate function.
//iii. Finds and displays the student with the highest marks using pointer-based access.

#include <stdio.h>
#include <stdlib.h>
struct student{
  char name[100];
  int roll;
  float marks;
  };

void display_stu_data(struct student *s,int n){
    char name[100];
    for(int i=0;i<n;i++){
        printf("Name %s\trollno: %d\tmarks: %f\n",(s+i)->name,(s+i)->roll,(s+i)->marks);
    }
}
void highest(struct student *s, int n) {
     int highest = (s+0)->marks,index = 0;
    for (int i = 0; i < n - 1; i++) {
       if((s+i)->marks > highest){
        highest = (s+i)->marks;
        index = i;
       }
    }
    printf("Name %s\trollno: %d\tmarks: %f\n",(s+index)->name,(s+index)->roll,(s+index)->marks);
}

int main()
{
    int n;
    printf("enter the number of students \n");
    scanf("%d",&n);
    struct student stu[n];
    for(int i=0;i<n;i++){
        printf("enter student name \t");
        scanf("%s",stu[i].name);
        printf("enter roll\t");
        scanf("%d",&stu[i].roll);
        printf("marks\t");
        scanf("%f",&stu[i].marks);
    }
    display_stu_data(stu,n);
    printf("heights marks\n");
    highest(stu,n);
    return 0;
}
