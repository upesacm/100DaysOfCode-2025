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
Node* deleteNode(Node* head, int position) {
    if (head == NULL || position <= 0) return head;
    Node* current = head;
    if (position == 1) {
        head = current->next;
        if (head != NULL) head->prev = NULL;
        free(current);
        return head;
    }
    for (int i = 1; current != NULL && i < position; i++) {
        current = current->next;
    }
    if (current == NULL) return head;
    if (current->next != NULL) current->next->prev = current->prev;
    if (current->prev != NULL) current->prev->next = current->next;
    free(current);
    return head;
}
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
        if (current != NULL) printf(" <--> ");
    }
    printf("\n");
}
int main() {
    Node* head1 = createNode(1);
    head1->next = createNode(3);
    head1->next->prev = head1;
    head1->next->next = createNode(4);
    head1->next->next->prev = head1->next;
    printf("Original List: ");
    printList(head1);
    head1 = deleteNode(head1, 2);
    printf("After Deletion: ");
    printList(head1);
    Node* head2 = createNode(1);
    head2->next = createNode(5);
    head2->next->prev = head2;
    head2->next->next = createNode(2);
    head2->next->next->prev = head2->next;
    head2->next->next->next = createNode(9);
    head2->next->next->next->prev = head2->next->next;
    printf("Original List: ");
    printList(head2);
    head2 = deleteNode(head2, 1);
    printf("After Deletion: ");
    printList(head2);
    return 0;
}
