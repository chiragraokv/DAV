#include <stdio.h>
#include <stdlib.h>

// Structure definition for a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Global pointers for head and tail of the list
struct Node* head = NULL;
struct Node* tail = NULL;

// Function prototypes
void insertAtRear(int data);
void deleteFromRear();
void insertAtPosition(int data, int position);
void deleteFromPosition(int position);
void insertAfterValue(int data, int value);
void insertBeforeValue(int data, int value);
void traverseForward();
void traverseReverse();
void displayMenu();
int countNodes();
struct Node* findNodeWithValue(int value);
struct Node* createNode(int data);

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert an element at the rear end of the list
void insertAtRear(int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) return;
    
    if (head == NULL) {
        // List is empty
        head = tail = newNode;
    } else {
        // List is not empty
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    printf("Element %d inserted at the rear successfully.\n", data);
}

// Function to delete an element from the rear end of the list
void deleteFromRear() {
    if (head == NULL) {
        printf("List is empty. Cannot delete from rear.\n");
        return;
    }
    
    if (head == tail) {
        // Only one node in the list
        printf("Element %d deleted from rear.\n", head->data);
        free(head);
        head = tail = NULL;
    } else {
        // More than one node
        struct Node* temp = tail;
        printf("Element %d deleted from rear.\n", temp->data);
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
    }
}

// Function to count the number of nodes in the list
int countNodes() {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to insert an element at a given position
void insertAtPosition(int data, int position) {
    if (position < 1) {
        printf("Position should be >= 1.\n");
        return;
    }
    
    if (position == 1) {
        // Insert at beginning
        struct Node* newNode = createNode(data);
        if (newNode == NULL) return;
        
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        printf("Element %d inserted at position %d successfully.\n", data, position);
        return;
    }
    
    int totalNodes = countNodes();
    if (position > totalNodes + 1) {
        printf("Position %d is beyond the list size (%d). Cannot insert.\n", position, totalNodes);
        return;
    }
    
    if (position == totalNodes + 1) {
        // Insert at end
        insertAtRear(data);
        return;
    }
    
    // Insert at middle position
    struct Node* newNode = createNode(data);
    if (newNode == NULL) return;
    
    struct Node* current = head;
    for (int i = 1; i < position; i++) {
        current = current->next;
    }
    
    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;
    
    printf("Element %d inserted at position %d successfully.\n", data, position);
}

// Function to delete an element from a given position
void deleteFromPosition(int position) {
    if (head == NULL) {
        printf("List is empty. Cannot delete from position %d.\n", position);
        return;
    }
    
    if (position < 1) {
        printf("Position should be >= 1.\n");
        return;
    }
    
    int totalNodes = countNodes();
    if (position > totalNodes) {
        printf("Position %d is beyond the list size (%d). Cannot delete.\n", position, totalNodes);
        return;
    }
    
    if (position == 1) {
        // Delete from beginning
        struct Node* temp = head;
        printf("Element %d deleted from position %d.\n", temp->data, position);
        
        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
        free(temp);
        return;
    }
    
    if (position == totalNodes) {
        // Delete from end
        deleteFromRear();
        return;
    }
    
    // Delete from middle position
    struct Node* current = head;
    for (int i = 1; i < position; i++) {
        current = current->next;
    }
    
    printf("Element %d deleted from position %d.\n", current->data, position);
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
}

// Function to find a node with a specific value
struct Node* findNodeWithValue(int value) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to insert an element after a node containing a specific value
void insertAfterValue(int data, int value) {
    if (head == NULL) {
        printf("List is empty. Cannot insert after value %d.\n", value);
        return;
    }
    
    struct Node* targetNode = findNodeWithValue(value);
    if (targetNode == NULL) {
        printf("Value %d not found in the list. Cannot insert after it.\n", value);
        return;
    }
    
    struct Node* newNode = createNode(data);
    if (newNode == NULL) return;
    
    newNode->next = targetNode->next;
    newNode->prev = targetNode;
    
    if (targetNode->next != NULL) {
        targetNode->next->prev = newNode;
    } else {
        // targetNode is the tail
        tail = newNode;
    }
    
    targetNode->next = newNode;
    printf("Element %d inserted after value %d successfully.\n", data, value);
}

// Function to insert an element before a node containing a specific value
void insertBeforeValue(int data, int value) {
    if (head == NULL) {
        printf("List is empty. Cannot insert before value %d.\n", value);
        return;
    }
    
    struct Node* targetNode = findNodeWithValue(value);
    if (targetNode == NULL) {
        printf("Value %d not found in the list. Cannot insert before it.\n", value);
        return;
    }
    
    struct Node* newNode = createNode(data);
    if (newNode == NULL) return;
    
    newNode->next = targetNode;
    newNode->prev = targetNode->prev;
    
    if (targetNode->prev != NULL) {
        targetNode->prev->next = newNode;
    } else {
        // targetNode is the head
        head = newNode;
    }
    
    targetNode->prev = newNode;
    printf("Element %d inserted before value %d successfully.\n", data, value);
}

// Function to traverse the list in forward direction
void traverseForward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    printf("Forward traversal: ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

// Function to traverse the list in reverse direction
void traverseReverse() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    printf("Reverse traversal: ");
    struct Node* current = tail;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->prev != NULL) {
            printf(" -> ");
        }
        current = current->prev;
    }
    printf("\n");
}

// Function to display the menu
void displayMenu() {
    printf("\n=== DOUBLY LINKED LIST OPERATIONS ===\n");
    printf("1. Insert element at rear\n");
    printf("2. Delete element from rear\n");
    printf("3. Insert element at given position\n");
    printf("4. Delete element from given position\n");
    printf("5. Insert element after a specific value\n");
    printf("6. Insert element before a specific value\n");
    printf("7. Traverse list forward\n");
    printf("8. Traverse list reverse\n");
    printf("9. Exit\n");
    printf("Enter your choice: ");
}

// Main function
int main() {
    int choice, data, position, value;
    
    printf("Welcome to Doubly Linked List Operations Program!\n");
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element to insert at rear: ");
                scanf("%d", &data);
                insertAtRear(data);
                break;
                
            case 2:
                deleteFromRear();
                break;
                
            case 3:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                printf("Enter position (starting from 1): ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;
                
            case 4:
                printf("Enter position to delete from (starting from 1): ");
                scanf("%d", &position);
                deleteFromPosition(position);
                break;
                
            case 5:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                printf("Enter value after which to insert: ");
                scanf("%d", &value);
                insertAfterValue(data, value);
                break;
                
            case 6:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                printf("Enter value before which to insert: ");
                scanf("%d", &value);
                insertBeforeValue(data, value);
                break;
                
            case 7:
                traverseForward();
                break;
                
            case 8:
                traverseReverse();
                break;
                
            case 9:
                printf("Exiting program. Thank you!\n");
                // Free all remaining nodes
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);
                
            default:
                printf("Invalid choice! Please enter a number between 1-9.\n");
        }
    }
    
    return 0;
}
