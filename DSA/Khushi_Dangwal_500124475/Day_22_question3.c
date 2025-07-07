#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to print the linked list
void printLinkedList(struct Node* head) {
    struct Node* current = head;
    
    while (current != NULL) {
        printf("%d", current->data);
        
        // Only print space if not the last node
        if (current->next != NULL) {
            printf(" ");
        }
        
        current = current->next;
    }
    printf("\n"); 
}

// Helper function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Example 1: 1 -> 2
    struct Node* head1 = createNode(1);
    head1->next = createNode(2);
    
    printf("Linked List 1: ");
    printLinkedList(head1);
    
    // Example 2: 49 -> 10 -> 30
    struct Node* head2 = createNode(49);
    head2->next = createNode(10);
    head2->next->next = createNode(30);
    
    printf("Linked List 2: ");
    printLinkedList(head2);
    
    // Free allocated memory 
    free(head1->next);
    free(head1);
    free(head2->next->next);
    free(head2->next);
    free(head2);
    
    return 0;
}

