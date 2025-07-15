#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" <--> ");
        head = head->next;
    }
    printf("\n");
}

struct Node* reverseList(struct Node* head) {
    struct Node* temp = NULL;
    struct Node* current = head;
    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        if (!current->prev) return current;
        current = current->prev;
    }
    return head;
}

int main() {
    int n;
    scanf("%d", &n);
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->prev = tail;
        newNode->next = NULL;
        if (!head) head = newNode;
        if (tail) tail->next = newNode;
        tail = newNode;
    }
    head = reverseList(head);
    printList(head);
    return 0;
}
