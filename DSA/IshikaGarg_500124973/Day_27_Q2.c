#include <stdio.h>
#include <stdlib.h>

// Node definition
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Reverse the doubly linked list
struct Node* reverseDLL(struct Node* head) {
    if (head == NULL || head->next == NULL) return head;

    struct Node* current = head;
    struct Node* temp = NULL;

    // Traverse and swap next and prev for each node
    while (current != NULL) {
        // Swap next and prev
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to next node in original direction
        current = current->prev;
    }

    // New head will be the last node processed
    if (temp != NULL)
        head = temp->prev;

    return head;
}

// Print the list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" <-> ");
        temp = temp->next;
    }
    printf("\n");
}

// Sample usage
int main() {
    // Original list: 3 <-> 4 <-> 5
    struct Node* head = createNode(3);
    struct Node* second = createNode(4);
    struct Node* third = createNode(5);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    printf("Original List:\n");
    printList(head);

    head = reverseDLL(head);

    printf("Reversed List:\n");
    printList(head);

    return 0;
}
