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
Node* reverseLinkedList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
        if (current != NULL) {
            printf(" -> ");
        }
    }
    printf(" -> NULL\n");
}
int main() {
    Node* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(4);
    printf("Original List: ");
    printLinkedList(head1);
    head1 = reverseLinkedList(head1);
    printf("Reversed List: ");
    printLinkedList(head1);
    Node* head2 = createNode(2);
    head2->next = createNode(7);
    head2->next->next = createNode(10);
    head2->next->next->next = createNode(9);
    head2->next->next->next->next = createNode(8);
    printf("Original List: ");
    printLinkedList(head2);    
    head2 = reverseLinkedList(head2);
    printf("Reversed List: ");
    printLinkedList(head2);
    return 0;
}
