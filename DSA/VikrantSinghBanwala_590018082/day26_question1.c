#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
bool swapKthNodes(Node** head, int k) {
    if (*head == NULL || k <= 0) {
        return false;
    }
    Node* current = *head;
    int length = 0;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    if (k > length) {
        return false;
    }
    Node* kthFromStart = *head;
    Node* kthFromEnd = *head;
    Node* prevKthFromStart = NULL;
    Node* prevKthFromEnd = NULL;
    for (int i = 1; i < k; i++) {
        prevKthFromStart = kthFromStart;
        kthFromStart = kthFromStart->next;
    }
    for (int i = 1; i < length - k + 1; i++) {
        prevKthFromEnd = kthFromEnd;
        kthFromEnd = kthFromEnd->next;
    }
    if (kthFromStart == kthFromEnd) {
        return true;
    }
    if (prevKthFromStart != NULL) {
        prevKthFromStart->next = kthFromEnd;
    } else {
        *head = kthFromEnd;
    }
    if (prevKthFromEnd != NULL) {
        prevKthFromEnd->next = kthFromStart;
    } else {
        *head = kthFromStart;
    }
    Node* temp = kthFromStart->next;
    kthFromStart->next = kthFromEnd->next;
    kthFromEnd->next = temp;
    return true;
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
    printf("Original List: ");
    printLinkedList(head1);
    if (swapKthNodes(&head1, 1)) {
        printf("After swapping 1st nodes: ");
        printLinkedList(head1);
    } else {
        printf("Invalid k value.\n");
    }
    Node* head2 = createNode(1);
    head2->next = createNode(2);
    head2->next->next = createNode(3);
    head2->next->next->next = createNode(4);
    head2->next->next->next->next = createNode(5);
    printf("Original List: ");
    printLinkedList(head2);
    if (swapKthNodes(&head2, 7)) {
        printf("After swapping 7th nodes: ");
        printLinkedList(head2);
    } else {
        printf("Invalid k value.\n");
    }
    return 0;
}