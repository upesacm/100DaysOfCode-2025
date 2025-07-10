#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to remove duplicates from a sorted linked list
void removeDuplicates(struct Node* head) {
    struct Node* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            // Duplicate node found
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);  // Free memory
        } else {
            current = current->next;  // Move to next node if not duplicate
        }
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL)
            printf(" -> ");
        current = current->next;
    }
    printf("\n");
}

// Function to insert node at the end
void append(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Main function to test the code
int main() {
    struct Node* head = NULL;

    // Example 1: Input: 2 -> 2 -> 4 -> 5
    append(&head, 2);
    append(&head, 2);
    append(&head, 4);
    append(&head, 5);

    printf("Original List:\n");
    printList(head);

    removeDuplicates(head);

    printf("After Removing Duplicates:\n");
    printList(head);

    return 0;
}
