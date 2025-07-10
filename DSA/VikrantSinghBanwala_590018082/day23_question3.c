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
Node* deleteMiddle(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    free(slow);
    return head;
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
    printf("\n");
}
int main() {
    Node* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(4);
    head1->next->next->next->next = createNode(5);
    head1 = deleteMiddle(head1);
    printLinkedList(head1);
    Node* head2 = createNode(2);
    head2->next = createNode(4);
    head2->next->next = createNode(6);
    head2->next->next->next = createNode(7);
    head2->next->next->next->next = createNode(5);
    head2->next->next->next->next->next = createNode(1);
    head2 = deleteMiddle(head2);
    printLinkedList(head2);
    return 0;
}