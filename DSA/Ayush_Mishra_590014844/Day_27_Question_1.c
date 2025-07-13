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

struct Node* deleteAtPosition(struct Node* head, int x) {
    if (!head || x <= 0) return head;
    struct Node* temp = head;
    int i = 1;
    while (temp && i < x) {
        temp = temp->next;
        i++;
    }
    if (!temp) return head;
    if (temp->prev) temp->prev->next = temp->next;
    else head = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    free(temp);
    return head;
}

int main() {
    int n, x;
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
    scanf("%d", &x);
    head = deleteAtPosition(head, x);
    printList(head);
    return 0;
}
