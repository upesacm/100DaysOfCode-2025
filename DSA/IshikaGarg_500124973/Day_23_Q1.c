#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to find the kth node from the end
int findKthFromEnd(struct Node* head, int k) {
    struct Node* first = head;
    struct Node* second = head;

    // Move first k steps ahead
    for (int i = 0; i < k; i++) {
        if (first == NULL)
            return -1; // k > length
        first = first->next;
    }

    // Move both pointers until first reaches end
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    return second ? second->data : -1;
}

// Utility function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Utility to append at end
void append(struct Node** headRef, int data) {
    struct Node* node = newNode(data);
    if (*headRef == NULL) {
        *headRef = node;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next) temp = temp->next;
    temp->next = node;
}

// Utility to print list
void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}
