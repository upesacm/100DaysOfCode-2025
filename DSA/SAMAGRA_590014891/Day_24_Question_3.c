#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* appendNode(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* deleteAtPosition(struct Node* head, int x) {
    if (head == NULL || x <= 0)
        return head;

    if (x == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* current = head;
    for (int i = 1; i < x - 1 && current->next != NULL; i++) {
        current = current->next;
    }

    if (current->next == NULL)
        return head;

    struct Node* nodeToDelete = current->next;
    current->next = nodeToDelete->next;
    free(nodeToDelete);

    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, x, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d node values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = appendNode(head, value);
    }

    printf("Enter the position to delete (1-based): ");
    scanf("%d", &x);

    printf("Original List:\n");
    printList(head);

    head = deleteAtPosition(head, x);

    printf("List after deleting position %d:\n", x);
    printList(head);

    return 0;
}
