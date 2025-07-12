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
Node* removeKthNode(Node* head, int k) {
    if (head == NULL || k <= 0) return head;
    Node* current = head;
    Node* prev = NULL;
    int count = 1;
    while (current != NULL) {
        if (count % k == 0) {
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            Node* temp = current;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
        count++;
    }
    return head;
}
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
        if (current != NULL) printf(" -> ");
    }
    printf("\n");
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
    printf("Original List: ");
    printList(head1);
    head1 = removeKthNode(head1, 2);
    printf("After Removing Every 2nd Node: ");
    printList(head1);
    Node* head2 = createNode(1);
    head2->next = createNode(2);
    head2->next->next = createNode(3);
    head2->next->next->next = createNode(4);
    head2->next->next->next->next = createNode(5);
    head2->next->next->next->next->next = createNode(6);
    head2->next->next->next->next->next->next = createNode(7);
    head2->next->next->next->next->next->next->next = createNode(8);
    head2->next->next->next->next->next->next->next->next = createNode(9);
    head2->next->next->next->next->next->next->next->next->next = createNode(10);
    printf("Original List: ");
    printList(head2);
    head2 = removeKthNode(head2, 3);
    printf("After Removing Every 3rd Node: ");
    printList(head2);
    return 0;
}