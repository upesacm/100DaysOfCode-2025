#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void append(struct Node** head, int data) {
    struct Node* temp = newNode(data);
    if (*head == NULL) {
        *head = temp;
        return;
    }
    struct Node* curr = *head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf(" -> NULL\n");
}

struct Node* deleteAtPosition(struct Node* head, int x) {
    if (x < 1 || head == NULL) return head;

    if (x == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* curr = head;
    for (int i = 1; i < x - 1 && curr != NULL; i++) {
        curr = curr->next;
    }

    if (curr == NULL || curr->next == NULL) return head;

    struct Node* temp = curr->next;
    curr->next = temp->next;
    free(temp);

    return head;
}

int main() {
    struct Node* head = NULL;
    int arr[] = {1, 5, 2, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++) append(&head, arr[i]);

    printf("Original List:\n");
    printList(head);

    int pos = 2;
    head = deleteAtPosition(head, pos);

    printf("List after deleting node at position %d:\n", pos);
    printList(head);

    return 0;
}
