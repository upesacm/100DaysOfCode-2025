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
Node* deleteNode(Node* head, int x) {
    if (head == NULL) {
        return NULL; 
    }
    if (x == 1) {
        Node* temp = head;
        head = head->next;
        free(temp); 
        return head;}
    Node* current = head;
    for (int i = 1; i < x - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) {
        return head; 
    }
    Node* temp = current->next; 
    current->next = current->next->next;
    free(temp); 

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
    printf(" -> NULL\n");
}
int main() {
    Node* head1 = createNode(1);
    head1->next = createNode(3);
    head1->next->next = createNode(4);
    printf("Original List: ");
    printLinkedList(head1);
    head1 = deleteNode(head1, 3);
    printf("Modified List: ");
    printLinkedList(head1);
    Node* head2 = createNode(1);
    head2->next = createNode(5);
    head2->next->next = createNode(2);
    head2->next->next->next = createNode(9);
    printf("Original List: ");
    printLinkedList(head2);
    head2 = deleteNode(head2, 2);
    printf("Modified List: ");
    printLinkedList(head2);
    return 0;
}