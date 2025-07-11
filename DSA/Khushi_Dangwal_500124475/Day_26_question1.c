#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for singly-linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to count length of the list
int getLength(struct Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to swap kth node from start and kth from end
bool swapKthNode(struct Node** head_ref, int k) {
    int n = getLength(*head_ref);

    // If k is more than number of nodes
    if (k > n) return true;

    // If kth node from beginning and end are same, no need to swap
    if (2 * k - 1 == n) return true;

    // Find kth node from beginning and its previous node
    struct Node* x = *head_ref;
    struct Node* x_prev = NULL;
    for (int i = 1; i < k; i++) {
        x_prev = x;
        x = x->next;
    }

    // Find kth node from end and its previous node
    struct Node* y = *head_ref;
    struct Node* y_prev = NULL;
    for (int i = 1; i < n - k + 1; i++) {
        y_prev = y;
        y = y->next;
    }

    // If x_prev exists, then change its next to y
    if (x_prev) x_prev->next = y;
    else *head_ref = y;

    // If y_prev exists, then change its next to x
    if (y_prev) y_prev->next = x;
    else *head_ref = x;

    // Swap next pointers
    struct Node* temp = x->next;
    x->next = y->next;
    y->next = temp;

    return true;
}

// Helper to print the linked list
void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf("->");
        head = head->next;
    }
    printf("\n");
}

// Sample driver code
int main() {
    // Creating the list 1->2->3->4->5
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    int k = 2;

    printf("Original list:\n");
    printList(head);

    if (swapKthNode(&head, k)) {
        printf("After swapping %dth nodes from start and end:\n", k);
        printList(head);
    } else {
        printf("Swap failed.\n");
    }

    return 0;
}
