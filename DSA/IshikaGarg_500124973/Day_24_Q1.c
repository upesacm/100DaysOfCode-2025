#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to reverse the linked list
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;     // Store next node
        curr->next = prev;     // Reverse current node
        prev = curr;           // Move prev to current
        curr = next;           // Move to next node
    }

    return prev; // New head
}

// Helper function to insert at end
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

// Helper to print list
void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf(" -> NULL\n");
}

// Example usage
int main() {
    struct Node* head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    printf("Original: ");
    printList(head);
    head = reverseList(head);
    printf("Reversed: ");
    printList(head);
    return 0;
}
