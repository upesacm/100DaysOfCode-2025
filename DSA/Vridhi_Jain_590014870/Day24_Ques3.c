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

struct Node* deleteAtPosition(struct Node* head, int position) {
    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* current = head;
    for (int i = 1; current && i < position - 1; i++)
        current = current->next;
    if (!current || !current->next) return head;
    struct Node* nodeToDelete = current->next;
    current->next = nodeToDelete->next;
    free(nodeToDelete);
    return head;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d", head->value);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int totalNodes, number, position;
    scanf("%d", &totalNodes);
    for (int i = 0; i < totalNodes; i++) {
        scanf("%d", &number);
        head = addNode(head, number);
    }
    scanf("%d", &position);
    head = deleteAtPosition(head, position);
    printList(head);
    return 0;
}
