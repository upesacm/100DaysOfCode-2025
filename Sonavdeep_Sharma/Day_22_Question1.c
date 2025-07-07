#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Add node to end of list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Find middle of the list
struct Node* findMiddle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {
    struct Node* head = NULL;
    int n, val;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertAtEnd(&head, val);
    }

    struct Node* mid = findMiddle(head);
    if (mid)
        printf("Middle element: %d\n", mid->data);
    else
        printf("List is empty.\n");

    return 0;
}
