#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf(" -> NULL\n");
}

void deleteNAfterM(struct Node* head, int m, int n) {
    struct Node* curr = head;

    while (curr) {
        for (int i = 1; i < m && curr != NULL; i++)
            curr = curr->next;

        if (curr == NULL) return;

        struct Node* temp = curr->next;
        for (int i = 0; i < n && temp != NULL; i++) {
            struct Node* del = temp;
            temp = temp->next;
            free(del);
        }

        curr->next = temp;
        curr = temp;
    }
}

int main() {
    struct Node* head = createNode(9);
    head->next = createNode(1);
    head->next->next = createNode(3);
    head->next->next->next = createNode(5);
    head->next->next->next->next = createNode(9);
    head->next->next->next->next->next = createNode(4);
    head->next->next->next->next->next->next = createNode(10);
    head->next->next->next->next->next->next->next = createNode(1);

    printf("Original List: ");
    printList(head);

    deleteNAfterM(head, 2, 1);

    printf("After Deletion: ");
    printList(head);
    return 0;
}
