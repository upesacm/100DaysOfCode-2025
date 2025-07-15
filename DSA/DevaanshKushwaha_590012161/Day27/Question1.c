#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to delete node at position x
struct Node* deleteNode(struct Node* head, int x) {
    if (head == NULL || x <= 0) return head;

    struct Node* curr = head;
    int count = 1;

    // Traverse to the x-th node
    while (curr && count < x) {
        curr = curr->next;
        count++;
    }

    if (curr == NULL) return head;

    // If node to be deleted is head
    if (curr->prev == NULL) {
        head = curr->next;
        if (head) head->prev = NULL;
    } else {
        curr->prev->next = curr->next;
        if (curr->next) curr->next->prev = curr->prev;
    }

    free(curr);
    return head;
}
