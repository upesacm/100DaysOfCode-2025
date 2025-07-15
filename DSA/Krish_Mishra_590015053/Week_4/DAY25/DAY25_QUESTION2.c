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

void append(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    struct Node* result = NULL;
    struct Node** tail = &result;
    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data)
            head1 = head1->next;
        else if (head2->data < head1->data)
            head2 = head2->next;
        else {
            *tail = createNode(head1->data);
            tail = &((*tail)->next);
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    return result;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    struct Node *head1 = NULL, *head2 = NULL;
    int n1, n2, val;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        append(&head1, val);
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        append(&head2, val);
    }
    struct Node* intersection = getIntersection(head1, head2);
    printList(intersection);
    return 0;
}
