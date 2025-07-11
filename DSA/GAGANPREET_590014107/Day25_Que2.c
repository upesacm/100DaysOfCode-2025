#include<stdio.h>
#include<stdlib.h>
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
Node* findIntersection(Node* head1, Node* head2) {
    Node* intersectionHead = NULL;
    Node* intersectionTail = NULL;
    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            head1 = head1->next;
        } else if (head1->data > head2->data) {
            head2 = head2->next;
        } else {
            Node* newNode = createNode(head1->data);
            if (intersectionHead == NULL) {
                intersectionHead = newNode;
                intersectionTail = newNode;
            } else {
                intersectionTail->next = newNode;
                intersectionTail = newNode;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    return intersectionHead;
}
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
        if (current != NULL) {
            printf("->");
        }
    }
    printf("->NULL\n");
}
int main() {
    Node* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(4);
    head1->next->next->next->next = createNode(6);
    Node* head2 = createNode(2);
    head2->next = createNode(4);
    head2->next->next = createNode(6);
    head2->next->next->next = createNode(8);
    printf("Linked List 1: ");
    printLinkedList(head1);
    printf("Linked List 2: ");
    printLinkedList(head2);
    Node* intersection = findIntersection(head1, head2);
    printf("Intersection: ");
    printLinkedList(intersection);
    return 0;
}
