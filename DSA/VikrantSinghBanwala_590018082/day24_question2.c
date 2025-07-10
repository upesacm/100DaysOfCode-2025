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
void deleteNAfterM(Node* head, int m, int n) {
    Node* current = head;
    Node* temp;
    while (current != NULL) {
        for (int i = 0; i < m && current != NULL; i++) {
            current = current->next;
        }
        if (current == NULL) {
            break;
        }
        Node* toDelete = current->next;
        for (int i = 0; i < n && toDelete != NULL; i++) {
            temp = toDelete;
            toDelete = toDelete->next;
            free(temp);
        }
        current->next = toDelete;
        current = toDelete;
    }
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
    Node* head1 = createNode(9);
    head1->next = createNode(1);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(5);
    head1->next->next->next->next = createNode(9);
    head1->next->next->next->next->next = createNode(4);
    head1->next->next->next->next->next->next = createNode(10);
    head1->next->next->next->next->next->next->next = createNode(1);
    printf("Original List: ");
    printLinkedList(head1);  
    deleteNAfterM(head1, 2, 1);
    printf("Modified List: ");
    printLinkedList(head1);
    Node* head2 = createNode(1);
    head2->next = createNode(2);
    head2->next->next = createNode(3);
    head2->next->next->next = createNode(4);
    head2->next->next->next->next = createNode(5);
    head2->next->next->next->next->next = createNode(6);
    printf("Original List: ");
    printLinkedList(head2);
    deleteNAfterM(head2, 6, 1);
    printf("Modified List: ");
    printLinkedList(head2);
    return 0;
}