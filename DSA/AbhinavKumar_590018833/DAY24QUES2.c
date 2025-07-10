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

void deleteNafterM(struct Node* head, int m, int n) {
    struct Node* current = head;
    struct Node* temp;

    while (current) {
        for (int i = 1; i < m && current != NULL; i++) {
            current = current->next;
        }

        if (current == NULL) return;

        temp = current->next;
        for (int i = 0; i < n && temp != NULL; i++) {
            struct Node* del = temp;
            temp = temp->next;
            free(del);
        }

        current->next = temp;
        current = temp;
    }
}

int main() {
    struct Node* head = NULL;
    int arr[] = {9, 1, 3, 5, 9, 4, 10, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++) append(&head, arr[i]);

    printf("Original List:\n");
    printList(head);

    deleteNafterM(head, 2, 1);

    printf("Modified List:\n");
    printList(head);

    return 0;
}
