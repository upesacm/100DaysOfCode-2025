#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete a node at a given position
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        return NULL;
    }
    
    struct Node* current = head;
    
    // If position is 1 (delete head node)
    if (position == 1) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(current);
        return head;
    }
    
    // Traverse to the node at the given position
    for (int i = 1; current != NULL && i < position; i++) {
        current = current->next;
    }
    
    // If position is beyond the list length
    if (current == NULL) {
        return head;
    }
    
    // Update the previous node's next pointer
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    
    // Update the next node's prev pointer
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    
    free(current);
    return head;
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the implementation
int main() {
    struct Node* head = NULL;
    
    // Create the list 1 <-> 3 <-> 4
    insertEnd(&head, 1);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    
    printf("Original list: ");
    printList(head);
    
    // Delete node at position 3
    head = deleteAtPosition(head, 3);
    printf("After deleting position 3: ");
    printList(head);
    
    // Create another list 1 <-> 5 <-> 2 <-> 9
    struct Node* head2 = NULL;
    insertEnd(&head2, 1);
    insertEnd(&head2, 5);
    insertEnd(&head2, 2);
    insertEnd(&head2, 9);
    
    printf("\nOriginal list: ");
    printList(head2);
    
    // Delete node at position 1 (head)
    head2 = deleteAtPosition(head2, 1);
    printf("After deleting position 1: ");
    printList(head2);
    
    return 0;
}
