#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10000 // Assuming elements range within 0-9999

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertEnd(struct Node* head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (!head) return newNode;
    struct Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

void storeUnique(bool* hashSet, struct Node* head) {
    while (head) {
        hashSet[head->data] = true;
        head = head->next;
    }
}

struct Node* makeUnion(struct Node* head1, struct Node* head2) {
    bool hashSet[MAX] = { false };

    storeUnique(hashSet, head1);
    storeUnique(hashSet, head2);

    struct Node* unionHead = NULL;
    for (int i = 0; i < MAX; i++) {
        if (hashSet[i]) {
            unionHead = insertEnd(unionHead, i);
        }
    }
    return unionHead;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *L1 = NULL, *L2 = NULL;
    int n1, n2, val;

    printf("Enter number of nodes in L1: ");
    scanf("%d", &n1);
    printf("Enter values of L1: ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        L1 = insertEnd(L1, val);
    }

    printf("Enter number of nodes in L2: ");
    scanf("%d", &n2);
    printf("Enter values of L2: ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        L2 = insertEnd(L2, val);
    }

    struct Node* result = makeUnion(L1, L2);
    printf("Union: ");
    printList(result);

    return 0;
}
