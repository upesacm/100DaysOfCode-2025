#include <stdio.h>
#include <stdlib.h>

struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
};

struct DNode* createDNode(int data) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

struct DNode* insertEnd(struct DNode* head, int data) {
    struct DNode* newNode = createDNode(data);
    if (!head) return newNode;
    struct DNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

struct DNode* reverseList(struct DNode* head) {
    struct DNode *temp = NULL, *curr = head;
    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp) head = temp->prev;
    return head;
}

void printList(struct DNode* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" <-> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, val;
    struct DNode* head = NULL;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = insertEnd(head, val);
    }
    head = reverseList(head);
    printf("Reversed List:\n");
    printList(head);
    return 0;
}
