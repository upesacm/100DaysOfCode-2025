#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node* buildDoublyLinkedList(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* head = createNode(arr[0]);
    struct Node* current = head;

    for (int i = 1; i < n; i++) {
        struct Node* newNode = createNode(arr[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    return head;
}

struct Node* reverseDoublyLinkedList(struct Node* head) {
    struct Node* temp = NULL;
    struct Node* current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        head = temp->prev;
    }

    return head;
}

void printDoublyLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL)
            printf(" <-> ");
        current = current->next;
    }
    printf("\n");
}

int main() {
    int arr[] = {3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node* dll = buildDoublyLinkedList(arr, n);

    printf("Original DLL:\n");
    printDoublyLinkedList(dll);

    struct Node* reversed = reverseDoublyLinkedList(dll);
    printf("Reversed DLL:\n");
    printDoublyLinkedList(reversed);

    return 0;
}
