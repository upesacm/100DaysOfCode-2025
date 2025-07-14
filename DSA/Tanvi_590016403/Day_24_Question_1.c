#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Utility: Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Utility: Print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf(" -> NULL\n");
}

// 1. Reverse a Linked List (Iterative)
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// 2. Delete N nodes after M nodes
struct Node* deleteNafterM(struct Node* head, int m, int n) {
    struct Node* curr = head;
    struct Node* temp;
    while (curr) {
        // Skip M nodes
        for (int i = 1; i < m && curr != NULL; i++)
            curr = curr->next;

        if (curr == NULL)
            return head;

        // Start deletion from next node
        temp = curr->next;
        for (int i = 1; i <= n && temp != NULL; i++) {
            struct Node* del = temp;
            temp = temp->next;
            free(del);
        }

        // Connect current node to the node after deletions
        curr->next = temp;
        curr = temp;
    }
    return head;
}

// 3. Delete the xth node in a singly linked list (1-based index)
struct Node* deleteAtPosition(struct Node* head, int x) {
    if (head == NULL)
        return NULL;

    struct Node* temp = head;

    if (x == 1) {
        head = head->next;
        free(temp);
        return head;
    }

    for (int i = 1; temp != NULL && i < x - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
        return head;

    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;

    return head;
}

// Utility: Insert node at the end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

// Demo Main
int main() {
    // Initial linked list: 1 -> 2 -> 3 -> 4
    struct Node* head = NULL;
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);

    printf("Original List:\n");
    printList(head);

    // Reverse
    head = reverseList(head);
    printf("\nReversed List:\n");
    printList(head);

    // Add more nodes: 5 -> 6 -> 7 -> 8
    head = insertEnd(head, 5);
    head = insertEnd(head, 6);
    head = insertEnd(head, 7);
    head = insertEnd(head, 8);
    printf("\nExtended List:\n");
    printList(head);

    // Delete 2 nodes after skipping 3 nodes
    head = deleteNafterM(head, 3, 2);
    printf("\nList after deleting 2 nodes after every 3 nodes:\n");
    printList(head);

    // Delete node at position 3
    head = deleteAtPosition(head, 3);
    printf("\nList after deleting node at position 3:\n");
    printList(head);

    return 0;
}
