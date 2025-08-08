#include <stdio.h>
#include <stdlib.h>
//Write a C program to define a student structure with the data members to store name,
//roll no and grade of the student. Also write the required functions to read, display, and
//sort student information according to the roll number of the student. All the member
//functions will have array of objects as arguments.
struct student{
  char name[100];
  int roll;
  float cg;
  };

void display_stu_data(struct student *s,int n){
    char name[100];
    for(int i=0;i<n;i++){
        printf("Name %s  rollno: %d  CGPA: %f",(s+i)->name,(s+i)->roll,(s+i)->cg);
    }
}
int main()
{
    int n;
    printf("enter the number of students \n");
    scanf("%d",n);
    struct student stu[n];
    for(int i=0;i<n;i++){
        printf("enter student name, roll and cg\n");
        gets(stu[i].name);
        scanf("%d",stu[i].roll);
        scanf("%f",stu[i].cg);
    }
    display_stu_data(stu,n);
    return 0;
}
