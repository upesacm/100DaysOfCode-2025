#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

struct Node* addNode(struct Node* head, int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->value = data;
    newNode->next = NULL;
    if (!head) return newNode;
    struct Node* current = head;
    while (current->next) current = current->next;
    current->next = newNode;
    return head;
}

struct Node* reverseList(struct Node* head) {
    struct Node* previous = NULL;
    struct Node* current = head;
    while (current) {
        struct Node* nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }
    return previous;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d", head->value);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf(" -> NULL\n");
}

int main() {
    struct Node* head = NULL;
    int totalNodes, number;
    scanf("%d", &totalNodes);
    for (int i = 0; i < totalNodes; i++) {
        scanf("%d", &number);
        head = addNode(head, number);
    }
    head = reverseList(head);
    printList(head);
    return 0;
}
