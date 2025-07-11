
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* sortedIntersection(Node* head1, Node* head2) {
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;

    while (head1 && head2) {
        if (head1->data < head2->data)
            head1 = head1->next;
        else if (head1->data > head2->data)
            head2 = head2->next;
        else {
            tail->next = createNode(head1->data);
            tail = tail->next;
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    return dummy.next;
}

void printList(Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf("->");
        head = head->next;
    }
    printf("\n");
}

void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* l1 = createNode(1);
    l1->next = createNode(2);
    l1->next->next = createNode(3);
    l1->next->next->next = createNode(4);
    l1->next->next->next->next = createNode(6);

    Node* l2 = createNode(2);
    l2->next = createNode(4);
    l2->next->next = createNode(6);
    l2->next->next->next = createNode(8);

    Node* result = sortedIntersection(l1, l2);
    printList(result);

    freeList(l1);
    freeList(l2);
    freeList(result);
    return 0;
}
