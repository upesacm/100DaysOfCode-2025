#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to reverse the doubly linked list
struct Node* reverseDLL(struct Node* head) {
    struct Node* temp = NULL;
    struct Node* current = head;

    // Swap prev and next pointers for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;  // Move to next node in original direction
    }

    // After reversing, temp will be at the node before new head
    if (temp != NULL)
        head = temp->prev;

    return head;
}
