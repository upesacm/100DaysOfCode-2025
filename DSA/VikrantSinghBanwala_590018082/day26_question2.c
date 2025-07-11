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
void insertSorted(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL || (*head)->data > data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }
    if (current->data != data) {
        newNode->next = current->next;
        current->next = newNode;
    }
}
Node* makeUnion(Node* L1, Node* L2) {
    Node* unionList = NULL;
    while (L1 != NULL) {
        insertSorted(&unionList, L1->data);
        L1 = L1->next;
    }
    while (L2 != NULL) {
        insertSorted(&unionList, L2->data);
        L2 = L2->next;
    }
    return unionList;
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
    Node* L1 = createNode(9);
    L1->next = createNode(6);
    L1->next->next = createNode(4);
    L1->next->next->next = createNode(2);
    L1->next->next->next->next = createNode(3);
    L1->next->next->next->next->next = createNode(8);
    Node* L2 = createNode(1);
    L2->next = createNode(2);
    L2->next->next = createNode(8);
    L2->next->next->next = createNode(6);
    L2->next->next->next->next = createNode(2);
    printf("List 1: ");
    printLinkedList(L1);
    printf("List 2: ");
    printLinkedList(L2);
    Node* unionList = makeUnion(L1, L2);
    printf("Union: ");
    printLinkedList(unionList);
    Node* L3 = createNode(1);
    L3->next = createNode(5);
    L3->next->next = createNode(1);
    L3->next->next->next = createNode(2);
    L3->next->next->next->next = createNode(2);
    L3->next->next->next->next->next = createNode(5);
    Node* L4 = createNode(4);
    L4->next = createNode(5);
    L4->next->next = createNode(6);
    L4->next->next->next = createNode(7);
    L4->next->next->next->next = createNode(1);
    printf("List 3: ");
    printLinkedList(L3);
    printf("List 4: ");
    printLinkedList(L4);
    Node* unionList2 = makeUnion(L3, L4);
    printf("Union: ");
    printLinkedList(unionList2);
    return 0;
}