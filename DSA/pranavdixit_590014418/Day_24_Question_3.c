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

void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf(" -> NULL\n");
}

struct Node* deleteAtPosition(struct Node* head, int x) {
    if (head == NULL) return head;

    if (x == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* curr = head;
    for (int i = 1; curr != NULL && i < x - 1; i++) {
        curr = curr->next;
    }

    if (curr == NULL || curr->next == NULL)
        return head;

    struct Node* temp = curr->next;
    curr->next = temp->next;
    free(temp);

    return head;
}

int main() {
    struct Node* head = createNode(1);
    head->next = createNode(5);
    head->next->next = createNode(2);
    head->next->next->next = createNode(9);

    printf("Original List: ");
    printList(head);

    head = deleteAtPosition(head, 2);

    printf("After Deleting 2nd Node: ");
    printList(head);
    return 0;
}
