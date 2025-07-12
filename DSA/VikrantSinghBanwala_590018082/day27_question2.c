#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
Node* reverseDoublyLinkedList(Node* head) {
    Node* current = head;
    Node* temp = NULL;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) head = temp->prev;
    return head;
}
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
        if (current != NULL) printf(" <-> ");
    }
    printf("\n");
}
int main() {
    Node* head1 = createNode(3);
    head1->next = createNode(4);
    head1->next->prev = head1;
    head1->next->next = createNode(5);
    head1->next->next->prev = head1->next;
    printf("Original List: ");
    printList(head1);
    head1 = reverseDoublyLinkedList(head1);
    printf("Reversed List: ");
    printList(head1);
    Node* head2 = createNode(75);
    head2->next = createNode(122);
    head2->next->prev = head2;
    head2->next->next = createNode(59);
    head2->next->next->prev = head2->next;
    head2->next->next->next = createNode(196);
    head2->next->next->next->prev = head2->next->next;
    printf("Original List: ");
    printList(head2);
    head2 = reverseDoublyLinkedList(head2);
    printf("Reversed List: ");
    printList(head2);
    return 0;
}