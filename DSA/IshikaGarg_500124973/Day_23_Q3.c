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

// Function to append node at the end
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

// Function to delete the middle node
struct Node* deleteMiddle(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        // Only one node or empty list
        free(head);
        return NULL;
    }

    struct Node *slow = head, *fast = head;
    struct Node *prev = NULL;

    // Use slow and fast pointer approach
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    // Delete the middle node (slow)
    prev->next = slow->next;
    free(slow);

    return head;
}

// Main function to test
int main() {
    struct Node* head = NULL;

    // Example 1: 1 -> 2 -> 3 -> 4 -> 5
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    printf("Original List:\n");
    printList(head);

    head = deleteMiddle(head);

    printf("After Deleting Middle:\n");
    printList(head);

    // Example 2: 2 -> 4 -> 6 -> 7 -> 5 -> 1
    struct Node* head2 = NULL;
    append(&head2, 2);
    append(&head2, 4);
    append(&head2, 6);
    append(&head2, 7);
    append(&head2, 5);
    append(&head2, 1);

    printf("\nOriginal List:\n");
    printList(head2);

    head2 = deleteMiddle(head2);

    printf("After Deleting Middle:\n");
    printList(head2);

    return 0;
}
