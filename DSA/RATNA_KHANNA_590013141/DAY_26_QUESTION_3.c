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

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* sortList(struct Node* head) {
    struct Node *zeroHead = NULL, *zeroTail = NULL;
    struct Node *oneHead = NULL, *oneTail = NULL;
    struct Node *twoHead = NULL, *twoTail = NULL;
    struct Node* curr = head;

    while (curr != NULL) {
        if (curr->data == 0) {
            if (zeroHead == NULL)
                zeroHead = zeroTail = curr;
            else {
                zeroTail->next = curr;
                zeroTail = curr;
            }
        } else if (curr->data == 1) {
            if (oneHead == NULL)
                oneHead = oneTail = curr;
            else {
                oneTail->next = curr;
                oneTail = curr;
            }
        } else {
            if (twoHead == NULL)
                twoHead = twoTail = curr;
            else {
                twoTail->next = curr;
                twoTail = curr;
            }
        }
        curr = curr->next;
    }

    if (zeroTail != NULL)
        zeroTail->next = oneHead ? oneHead : twoHead;
    if (oneTail != NULL)
        oneTail->next = twoHead;
    if (twoTail != NULL)
        twoTail->next = NULL;

    if (zeroHead != NULL)
        return zeroHead;
    else if (oneHead != NULL)
        return oneHead;
    else
        return twoHead;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

struct Node* createList(int n) {
    struct Node* head = NULL;
    int val;
    for (int i = 0; i < n; i++) {
        printf("Enter element %d (0, 1, or 2): ", i + 1);
        scanf("%d", &val);
        head = insertEnd(head, val);
    }
    return head;
}

int main() {
    int n;
    struct Node* head = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    head = createList(n);
    head = sortList(head);

    printf("\nSorted Linked List:\n");
    printList(head);

    return 0;
}
