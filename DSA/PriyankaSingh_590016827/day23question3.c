#include <stdio.h>
#include <stdlib.h>

// Definition of a node
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Append a node at the end
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

// Function to delete the middle node
struct Node* deleteMiddle(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        // Single node case
        free(head);
        return NULL;
    }

    struct Node *slow = head, *fast = head;
    struct Node *prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    // Delete slow (middle node)
    prev->next = slow->next;
    free(slow);

    return head;
}

// Print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d node values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        append(&head, value);
    }

    printf("Original list:\n");
    printList(head);

    head = deleteMiddle(head);

    printf("List after deleting middle node:\n");
    if (head == NULL)
        printf("List is now empty.\n");
    else
        printList(head);

    return 0;
}
