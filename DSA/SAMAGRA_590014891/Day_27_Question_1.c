#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

struct Node* deleteNode(struct Node* head, int x) {
    if (head == NULL) return NULL;

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

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" <--> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    head = insertEnd(head, 1);
    head = insertEnd(head, 5);
    head = insertEnd(head, 2);
    head = insertEnd(head, 9);

    int x = 1;
    head = deleteNode(head, x);

    printList(head);

    return 0;
}
