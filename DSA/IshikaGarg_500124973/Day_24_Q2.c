#include <stdio.h>
#include <stdlib.h>

// Define a node
struct Node {
    int data;
    struct Node* next;
};

// Insert node at end
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
}

// Print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
    printf(" -> NULL\n");
}

// Function to delete n nodes after skipping m nodes
void deleteNafterM(struct Node* head, int m, int n) {
    struct Node* curr = head;
    struct Node* temp;
    int count;

    while (curr) {
        // Skip M nodes
        for (count = 1; count < m && curr != NULL; count++)
            curr = curr->next;

        // If we reached end of list, break
        if (curr == NULL || curr->next == NULL)
            break;

        // Start deletion of next N nodes
        temp = curr->next;
        for (count = 1; count <= n && temp != NULL; count++) {
            struct Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }

        // Connect the Mth node to the (M+N+1)th node
        curr->next = temp;

        // Move to the next block of M nodes
        curr = temp;
    }
}

// Main function to test
int main() {
    struct Node* head = NULL;

    // Example 1: Linked List: 9->1->3->5->9->4->10->1, m = 2, n = 1
    int arr[] = {9, 1, 3, 5, 9, 4, 10, 1};
    int m = 2, n = 1;
    for (int i = 0; i < 8; i++)
        insert(&head, arr[i]);

    printf("Original list:\n");
    printList(head);

    deleteNafterM(head, m, n);

    printf("Modified list after deleting %d nodes after every %d nodes:\n", n, m);
    printList(head);

    return 0;
}
