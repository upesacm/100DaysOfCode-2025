#include <stdio.h>
#include <stdlib.h>

struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
};

struct DNode* createDNode(int data) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

struct DNode* insertEnd(struct DNode* head, int data) {
    struct DNode* newNode = createDNode(data);
    if (!head) return newNode;
    struct DNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

struct DNode* deleteAtPos(struct DNode* head, int pos) {
    if (!head) return NULL;
    struct DNode* temp = head;
    if (pos == 1) {
        head = head->next;
        if (head) head->prev = NULL;
        free(temp);
        return head;
    }
    for (int i = 1; temp && i < pos; i++)
        temp = temp->next;
    if (!temp) return head;
    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    free(temp);
    return head;
}

void printList(struct DNode* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" <-> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, x, val;
    struct DNode* head = NULL;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = insertEnd(head, val);
    }
    printf("Enter position to delete: ");
    scanf("%d", &x);
    head = deleteAtPos(head, x);
    printf("Updated List:\n");
    printList(head);
    return 0;
}
