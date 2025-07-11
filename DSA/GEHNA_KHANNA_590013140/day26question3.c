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

struct Node* sortList(struct Node* head) {
    struct Node zeroDummy, oneDummy, twoDummy;
    struct Node *zero = &zeroDummy, *one = &oneDummy, *two = &twoDummy;
    zero->next = one->next = two->next = NULL;

    while (head) {
        if (head->data == 0) {
            zero->next = head;
            zero = zero->next;
        } else if (head->data == 1) {
            one->next = head;
            one = one->next;
        } else {
            two->next = head;
            two = two->next;
        }
        head = head->next;
    }

    two->next = NULL;
    one->next = twoDummy.next;
    zero->next = oneDummy.next;

    return zeroDummy.next;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

int main() {
    struct Node* head = NULL;
    int arr[] = {1, 2, 2, 1, 2, 0, 2, 2};
    for (int i = 0; i < 8; i++) {
        append(&head, arr[i]);
    }

    head = sortList(head);
    printList(head);
    return 0;
}
