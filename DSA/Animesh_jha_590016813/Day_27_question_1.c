#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* deleteNode(struct Node* head, int x) {
    if (head == NULL || x <= 0)
        return head;

    struct Node* temp = head;

    if (x == 1) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return head;
    }

    for (int i = 1; temp != NULL && i < x; i++)
        temp = temp->next;

    if (temp == NULL)
        return head;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
    return head;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d", node->data);
        if (node->next)
            printf(" <--> ");
        node = node->next;
    }
    printf("\n");
}

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

int main() {
    struct Node* head = NULL;
    head = insertEnd(head, 1);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);

    printf("Original list:\n");
    printList(head);

    int x = 3;
    head = deleteNode(head, x);

    printf("List after deleting node at position %d:\n", x);
    printList(head);

    return 0;
}
