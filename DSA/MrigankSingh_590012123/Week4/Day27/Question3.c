#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

Node* removeKthNode(Node* head, int k) {
    if (head == NULL || k <= 0) {
        return head;
    }
    if (k == 1) {
        Node* current = head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
        return NULL;
    }
    Node* current = head;
    Node* prev = NULL;
    int count = 1;
    while (current != NULL) {
        if (count % k == 0) {
            prev->next = current->next;
            free(current);
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
        count++;
    }
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int size, data, k;
    Node* head = NULL;

    printf("Enter the size of the linked list (must be > 0): ");
    scanf("%d", &size);
    if (size <= 0) {
        fprintf(stderr, "Invalid size. Size must be greater than 0.\n");
        return EXIT_FAILURE;
    }

    printf("Enter the elements of the linked list: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    printf("Enter the value of k (must be > 0): ");
    scanf("%d", &k);
    if (k <= 0) {
        fprintf(stderr, "Invalid k. k must be greater than 0.\n");
        freeList(head);
        return EXIT_FAILURE;
    }

    printf("Original list: ");
    printList(head);

    head = removeKthNode(head, k);

    printf("Modified list: ");
    printList(head);

    freeList(head);

    return EXIT_SUCCESS;
}