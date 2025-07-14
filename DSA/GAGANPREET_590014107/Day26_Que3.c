
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
void sortLinkedList(Node** head) {
    Node* zeroHead = NULL;
    Node* oneHead = NULL;
    Node* twoHead = NULL;
    Node* zeroTail = NULL;
    Node* oneTail = NULL;
    Node* twoTail = NULL;

    Node* current = *head;
    while (current != NULL) {
        if (current->data == 0) {
            if (zeroHead == NULL) {
                zeroHead = current;
                zeroTail = current;
            } else {
                zeroTail->next = current;
                zeroTail = zeroTail->next;
            }
        } else if (current->data == 1) {
            if (oneHead == NULL) {
                oneHead = current;
                oneTail = current;
            } else {
                oneTail->next = current;
                oneTail = oneTail->next;
            }
        } else {
            if (twoHead == NULL) {
                twoHead = current;
                twoTail = current;
            } else {
                twoTail->next = current;
                twoTail = twoTail->next;
            }
        }
        current = current->next;
    }
    if (zeroTail != NULL) {
        zeroTail->next = oneHead;
    } else {
        zeroHead = oneHead;
    }
    if (oneTail != NULL) {
        oneTail->next = twoHead;
    }
    if (twoTail != NULL) {
        twoTail->next = NULL;
    }
    *head = zeroHead ? zeroHead : (oneHead ? oneHead : twoHead);
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
    head1->next->next = createNode(2);
    head1->next->next->next = createNode(1);
    head1->next->next->next->next = createNode(2);
    head1->next->next->next->next->next = createNode(0);
    head1->next->next->next->next->next->next = createNode(2);
    head1->next->next->next->next->next->next->next = createNode(2);
    printf("Original List: ");
    printLinkedList(head1);
    sortLinkedList(&head1);
    printf("Sorted List: ");
    printLinkedList(head1);
    Node* head2 = createNode(2);
    head2->next = createNode(2);
    head2->next->next = createNode(0);
    head2->next->next->next = createNode(1);
    printf("Original List: ");
    printLinkedList(head2);
    sortLinkedList(&head2);
    printf("Sorted List: ");
    printLinkedList(head2);
    return 0;
}
