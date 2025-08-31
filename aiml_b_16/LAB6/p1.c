#include<stdio.h>
#include<stdlib.h>
//create a linked list recursively
typedef struct Node{
    int data;
    struct Node* next;
}Node;
Node* create(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
Node* create_LL(int size){
    int data;
    Node* new_node = create(size);
    Node* current;
    if(size == 0){
        current = new_node;
        return current;
    }
    else{
        new_node->next = create_LL(size-1);
        return new_node;// this is the head
    }
}
Node* allocate_LL(Node* head){
    Node* current = head;
    int i = 0;
    while(current->next != NULL){
            printf("%d \t",current->data);
            current = current->next;
    }
    return head;
}

void main(){
    int i = 5;
    Node* head = NULL;
    head = create_LL(i);
    allocate_LL(head);

}
