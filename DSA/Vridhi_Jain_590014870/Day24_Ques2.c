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

struct Node* deleteNAfterM(struct Node* head, int mCount, int nCount) {
    struct Node* current = head;
    while (current) {
        for (int i = 1; i < mCount && current; i++)
            current = current->next;
        if (!current) break;
        struct Node* temp = current->next;
        for (int i = 0; i < nCount && temp; i++) {
            struct Node* deleteNode = temp;
            temp = temp->next;
            free(deleteNode);
        }
        current->next = temp;
        current = temp;
    }
    return head;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d", head->value);
        if (head->next) printf("->");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int totalNodes, number, m, n;
    scanf("%d", &totalNodes);
    for (int i = 0; i < totalNodes; i++) {
        scanf("%d", &number);
        head = addNode(head, number);
    }
    scanf("%d%d", &m, &n);
    head = deleteNAfterM(head, m, n);
    printList(head);
    return 0;
}
