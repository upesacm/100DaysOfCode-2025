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
int findKthFromEnd(Node* head, int k) {
    Node* fast = head;
    Node* slow = head;
    for (int i = 0; i < k; i++) {
        if (fast == NULL) {
            return -1;
        }
        fast = fast->next;
    }
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
}
int main() {
    Node* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(4);
    head1->next->next->next->next = createNode(5);
    head1->next->next->next->next->next = createNode(6);
    head1->next->next->next->next->next->next = createNode(7);
    head1->next->next->next->next->next->next->next = createNode(8);
    head1->next->next->next->next->next->next->next->next = createNode(9);
    int k1 = 2;
    int result1 = findKthFromEnd(head1, k1);
    printf("%d\n", result1);
    Node* head2 = createNode(10);
    head2->next = createNode(5);
    head2->next->next = createNode(100);
    head2->next->next->next = createNode(5);
    int k2 = 5;
    int result2 = findKthFromEnd(head2, k2);
    printf("%d\n", result2);
    return 0;
}