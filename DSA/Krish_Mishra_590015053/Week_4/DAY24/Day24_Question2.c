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
void append(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void deleteNAfterM(struct Node* head, int m, int n) {
    struct Node* current = head;
    struct Node* temp;
    int i, j;
    while (current != NULL) {
        for (i = 1; i < m && current != NULL; i++)
            current = current->next;
        if (current == NULL)
            return;
        temp = current->next;
        for (j = 0; j < n && temp != NULL; j++) {
            struct Node* next = temp->next;
            free(temp);
            temp = next;
        }
        current->next = temp;
        current = temp;
    }
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    struct Node* head = NULL;
    int n, val, m_del, n_del;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&head, val);
    }
    scanf("%d %d", &m_del, &n_del);
    deleteNAfterM(head, m_del, n_del);
    printList(head);
    return 0;
}
