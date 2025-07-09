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
Node* removeDuplicates(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* current = head;
    while (current->next != NULL) {
        if (current->data == current->next->data) {
            Node* duplicate = current->next;
            current->next = current->next->next;
            free(duplicate);
        } else {
            current = current->next;
        }
    }
    return head;
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
    printf("\n");
}
int main() {
    Node* head1 = createNode(2);
    head1->next = createNode(2);
    head1->next->next = createNode(4);
    head1->next->next->next = createNode(5);
    head1 = removeDuplicates(head1);
    printLinkedList(head1);
    Node* head2 = createNode(2);
    head2->next = createNode(2);
    head2->next->next = createNode(2);
    head2->next->next->next = createNode(2);
    head2->next->next->next->next = createNode(2);
    head2 = removeDuplicates(head2);
    printLinkedList(head2);
    return 0;
}
