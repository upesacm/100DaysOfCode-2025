
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int findKthFromEnd(struct Node* head, int k) {
    struct Node *first = head, *second = head;

    for (int i = 0; i < k; i++) {
        if (first == NULL) return -1;  
        first = first->next;
    }

    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    return (second != NULL) ? second->data : -1;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next= newNode(6);
    head->next->next->next->next->next->next= newNode(7);
    head->next->next->next->next->next->next->next = newNode(8);
    head->next->next->next->next->next->next->next->next = newNode(9);

    int k = 2;

    printf("Linked List:\n");
    printList(head);

    int result = findKthFromEnd(head, k);
    printf("Output: %d\n", result);  

    return 0;
}
