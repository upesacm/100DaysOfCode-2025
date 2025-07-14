#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to count nodes
int countNodes(struct Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to swap kth nodes, returns true(1) if swapped, false(0) if not
int swapKthNode(struct Node** headRef, int k) {
    struct Node* head = *headRef;
    int n = countNodes(head);

    // If k is more than number of nodes, return false
    if (k > n)
        return false;

    // If kth node from start and end are same, no swap needed
    if (2 * k - 1 == n)
        return false;

    // Find kth node from start and its previous
    struct Node* x = head;
    struct Node* prevX = NULL;
    for (int i = 1; i < k; i++) {
        prevX = x;
        x = x->next;
    }

    // Find kth node from end and its previous
    struct Node* y = head;
    struct Node* prevY = NULL;
    for (int i = 1; i < n - k + 1; i++) {
        prevY = y;
        y = y->next;
    }

    // Swap previous pointers
    if (prevX != NULL)
        prevX->next = y;
    else
        *headRef = y;

    if (prevY != NULL)
        prevY->next = x;
    else
        *headRef = x;

    // Swap next pointers
    struct Node* temp = x->next;
    x->next = y->next;
    y->next = temp;

    return true;
}

// Utility: create a node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Utility: insert node at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* temp = newNode(data);
    if (!head)
        return temp;

    struct Node* curr = head;
    while (curr->next)
        curr = curr->next;

    curr->next = temp;
    return head;
}

// Utility: print the list
void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// Main function to test
int main() {
    struct Node* head = NULL;

    // Create example list: 1->2->3->4
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);

    int k = 1;

    printf("Original List:\n");
    printList(head);

    int result = swapKthNode(&head, k);

    printf("After swapping %d-th node from start and end:\n", k);
    printList(head);

    if (result)
        printf("Output: true\n");
    else
        printf("Output: false\n");

    return 0;
}
