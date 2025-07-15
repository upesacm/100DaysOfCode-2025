#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

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

struct Node* deleteAtPosition(struct Node* head, int pos) {
    if (pos <= 0 || head == NULL)
        return head;
    if (pos == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* current = head;
    for (int i = 1; i < pos - 1 && current != NULL; i++)
        current = current->next;
    if (current == NULL || current->next == NULL)
        return head;
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    struct Node* head = NULL;
    int n, val, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&head, val);
    }
    scanf("%d", &x);
    head = deleteAtPosition(head, x);
    printList(head);
    return 0;
}
