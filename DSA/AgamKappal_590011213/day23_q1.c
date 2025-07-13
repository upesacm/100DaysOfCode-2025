
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

int kthFromEnd(struct Node* head, int k) {
    struct Node *first = head, *second = head;

    for (int i = 0; i < k; i++) {
        if (second == NULL) return -1;
        second = second->next;
    }

    while (second != NULL) {
        first = first->next;
        second = second->next;
    }

    if (first) return first->data;
    return -1;
}

int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    head->next->next->next->next->next->next = createNode(7);
    head->next->next->next->next->next->next->next = createNode(8);
    head->next->next->next->next->next->next->next->next = createNode(9);

    int k = 2;
    printf("%d\n", kthFromEnd(head, k));

    return 0;
}
