#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

bool exists(struct Node* head, int val) {
    while (head) {
        if (head->data == val) return true;
        head = head->next;
    }
    return false;
}

void sortedInsert(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= val) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next && current->next->data < val)
            current = current->next;
        newNode->next = current->next;
        current->next = newNode;
    }
}

struct Node* makeUnion(struct Node* head1, struct Node* head2) {
    struct Node* unionList = NULL;
    while (head1) {
        if (!exists(unionList, head1->data))
            sortedInsert(&unionList, head1->data);
        head1 = head1->next;
    }
    while (head2) {
        if (!exists(unionList, head2->data))
            sortedInsert(&unionList, head2->data);
        head2 = head2->next;
    }
    return unionList;
}
