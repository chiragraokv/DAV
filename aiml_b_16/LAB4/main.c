#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
int data;
struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
    printf("Memory allocation failed\n");
    exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

    // function to insert node before the given node
Node* ins_before(Node* head, int given,int data){
    printf("inside\n");
    Node* newNode = createNode(data);
        if(head == NULL){
        head = newNode;
        printf("Null");
        }
        // find the given node and insert newNode before the given node
    else{
        Node* current = head;
        printf("here");
        while(current->next != NULL){
            Node* next_of_current = current ->next;
            if(next_of_current->data == given){
                // if next node of current node is same as given node, insert the new node here
                current->next = newNode;
                newNode->next = next_of_current;
                // assignt the links and exit
                free(current);
                return head;
            }
        }

    }
    return head;
}

Node* ins_after(Node* head,int given, int data){
    Node* newNode = createNode(data);
        if(head == NULL){
        head = newNode;
        }
        else{
        Node* current = head;
        while(current != NULL){
            if(current->data == given){
                //insert new node after the given node
                newNode->next = current->next;
                current->next = newNode;
                return head;
            }
        }
        free(current);
}
    return head;
}


//insert element at the end of the node
Node* insert(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
    head = newNode;
    }
    else {
        Node* current = head;
    while (current->next != NULL)
        current = current->next;
        current->next = newNode;
    }
        return head;
    }

Node* delete_node(Node* head, int data) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return NULL;
    }
    Node* current = head;
    Node* prev = NULL;
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Element not found in the linked list.\n");
        return head;
    }
    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
    printf("Element deleted successfully.\n");
    return head;
}
Node* sort_list(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* current = head;
    while (current != NULL) {
        Node* min_node = current;
        Node* traverse = current->next;
        while (traverse != NULL) {
            if (traverse->data < min_node->data) {
                min_node = traverse;
            }
            traverse = traverse->next;
        }
        int temp_data = current->data;
        current->data = min_node->data;
        min_node->data = temp_data;
        current = current->next;
    }
    return head;
}
Node* reverse_list(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node* delete_alternate(Node* head){
    Node* current = head;
    Node* prev = NULL;
    Node* next = NULL;
    int flag = 0;
    while(current != NULL){
        if(flag % 2 == 0){
            flag++;
             prev = current;
            current = current->next;
        }
        else{
            flag++;
            next = current->next;
            prev->next = next;
            free(current);
            current = next;
        }
    }
    return head;
}
void display_node(Node* head){
    printf("display elements\n");
    Node* current = head;
    while(current != NULL){
        printf("%d \t",current->data);
        current = current->next;
    }
    printf("\n");
    return;
}

int main()
{
    int choice,data,n;
    Node* head = NULL;
    printf("Use 0 to insert element\n1 to insert element before a given element\n2 to insert element after given element\n3 to delete specific element\n4 to display \n5 to reverse \n6 to sort \n7 to delete alternate ");
    while(1){

    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice){
    case 0:
        printf("enter element to insert:\n");
        scanf("%d",&data);
        head = insert(head,data);
        break;
    case 1:
        // insert before the given element
        printf("enter the element\n");
        scanf("%d",&data);
        printf("enter the Node\n");
        scanf("%d",&n);
        head = ins_before(head,n,data);
        display_node(head);
        break;
    case 2:
        // Insert an element after another specified element in the list
        printf("enter the element\n");
        scanf("%d",&data);
        printf("enter the Node\n");
        scanf("%d",&n);
        head = ins_after(head,n,data);
        display_node(head);
        break;
    case 3:
        //Delete a specified element from the list
        printf("enter the element to delete\n");
        scanf("%d",&data);
        head = delete_node(head,data);
        display_node(head);
        break;
    case 4:
        //Traverse the list and display all elements
        display_node(head);
        break;
    case 5:
        //reverse the list
        head = reverse_list(head);
        display_node(head);
        break;
    case 6:
        //sort
        head = sort_list(head);
        display_node(head);
        break;
    case 7:
        //delete alternate
        head = delete_alternate(head);
        display_node(head);
        break;
    default:
        printf("wrong input\n");
        break;
    }
    }
    return 0;
}
