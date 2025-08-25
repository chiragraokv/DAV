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
        printf("Name %s\trollno: %d\tCGPA: %f\n",(s+i)->name,(s+i)->roll,(s+i)->cg);
    }
}
void sort_student(struct student *s, int n) {
    int i, j, min_idx;
    struct student temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (s[j].roll < s[min_idx].roll) {
                min_idx = j;
            }
        }
        temp = s[min_idx];
        s[min_idx] = s[i];
        s[i] = temp;
    }
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
        printf("cg\t");
        scanf("%f",&stu[i].cg);
    }
    display_stu_data(stu,n);
    sort_student(stu,n);
    printf("after sorting \n");
    display_stu_data(stu,n);
    return 0;
}
