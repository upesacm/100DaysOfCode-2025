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

// Function to reverse a doubly linked list
struct Node* reverseDoublyLinkedList(struct Node* head) {
    struct Node* current = head;
    struct Node* temp = NULL;
    
    // Swap next and prev pointers for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Move to the next node (original next)
    }
    
    // Before changing head, check for empty list or single node
    if (temp != NULL) {
        head = temp->prev;
    }
    
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
    
    // Create the list 3 <-> 4 <-> 5
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);
    
    printf("Original list: ");
    printList(head);
    
    // Reverse the list
    head = reverseDoublyLinkedList(head);
    printf("Reversed list: ");
    printList(head);
    
    // Create another list 75 <-> 122 <-> 59 <-> 196
    struct Node* head2 = NULL;
    insertEnd(&head2, 75);
    insertEnd(&head2, 122);
    insertEnd(&head2, 59);
    insertEnd(&head2, 196);
    
    printf("\nOriginal list: ");
    printList(head2);
    
    // Reverse the list
    head2 = reverseDoublyLinkedList(head2);
    printf("Reversed list: ");
    printList(head2);
    
    return 0;
}
