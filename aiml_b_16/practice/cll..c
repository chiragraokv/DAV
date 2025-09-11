#include<stdio.h>
#include<stdlib.h>
typedef struct  Node{
    int data;
    struct Node *next;
}Node;

Node* Create_node(int data){
    Node* new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
Node* sort(Node* head,Node* actual_head){
    Node* temp = head;
    if(head->next == NULL){
        return actual_head;
    }
    else{
        int small = head->data;
        
        while(temp->data > small || temp->next == NULL){
            temp = temp->next;
        }
    Node* swap_temp;
    swap_temp = temp;
    temp->data = head->data;
    temp->next = head->data;
    head->data = swap_temp->next;
    head->next = swap_temp->next;
    return sort(head->next,actual_head);
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