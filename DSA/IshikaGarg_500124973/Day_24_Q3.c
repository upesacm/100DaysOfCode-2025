#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert node at the end
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
    printf(" -> NULL\n");
}

// Function to delete the xth node (1-based index)
struct Node* deleteAtPosition(struct Node* head, int x) {
    if (head == NULL)
        return NULL;

    struct Node* temp = head;

    // If the head needs to be deleted
    if (x == 1) {
        head = head->next;
        free(temp);
        return head;
    }

    // Traverse to the (x-1)th node
    for (int i = 1; i < x - 1 && temp != NULL; i++)
        temp = temp->next;

    // If position is beyond list length or invalid
    if (temp == NULL || temp->next == NULL)
        return head;

    // Delete xth node
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);

    return head;
}

int main() {
    struct Node* head = NULL;

    insert(&head, 1);
    insert(&head, 3);
    insert(&head, 4);

    printf("Original list:\n");
    printList(head);

    int x = 3;
    head = deleteAtPosition(head, x);

    printf("After deleting %dth node:\n", x);
    printList(head);

    struct Node* head2 = NULL;
    insert(&head2, 1);
    insert(&head2, 5);
    insert(&head2, 2);
    insert(&head2, 9);

    printf("\nSecond list:\n");
    printList(head2);

    x = 2;
    head2 = deleteAtPosition(head2, x);

    printf("After deleting %dth node:\n", x);
    printList(head2);

    return 0;
}
