//Write a C program to implement a Circular Singly Linked List using First and Last pointers.
//Implement the following operations:
//i. Insertion at the end of the list using First and Last pointers.
//ii. Deletion from the beginning or end using First and Last pointers.
//iii. Display t
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* first = NULL;
Node* last = NULL;
Node* create(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert_node(int data){
    Node* new_n = create(data);
    if(first == NULL){
        first = new_n;
        last = new_n;
        first->next = last;
        last->next = first;
    }
    else{
        last->next= new_n;
        new_n->next = first;
        last = new_n;
    }
}
void delete_element(int element){
    Node* current = first;
    Node* prev = last;
    while(1){
            if(current->data == element) //got the node break
            {
                break;
            }
            else if(current ->next == first){
                printf("element not present");
                return;
            }
        prev = current;
        current = current->next;

    }
    prev->next = current->next;
    free(current);
    return;
}
void display_node(){
    while(1){
        Node* current = first;
        printf("%d\t",current->data);
        current  = current->next;
        if(current->next == first){
            return;
        }
    }
}
void display_menu(){
    printf("1: insert element\n2: delete element \n3: display elements\nenter choice\t");
}
int main(){
    while(1){
        display_menu();
        int choice;
        scanf("%d",&choice);
        switch (choice){
    case 1:
        int data;
        printf("enter element to insert:\t");
        scanf("%d",&data);
        insert_node(data);
        display_node();
        break;
    case 2:
         printf("enter element to delete:\t");
        scanf("%d",&data);
        delete_element(data);
        display_node();
        break;

    case 3:
        display_node();
        break;
    default:
        printf("wrong input");
        break;
    }}
}

