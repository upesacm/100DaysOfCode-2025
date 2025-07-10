#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Insert at end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

// Delete N nodes after M nodes repeatedly
struct Node* deleteNafterM(struct Node* head, int m, int n) {
    struct Node* curr = head;
    struct Node* temp;
    while (curr) {
        // Skip M nodes
        for (int i = 1; i < m && curr != NULL; i++)
            curr = curr->next;

        if (curr == NULL || curr->next == NULL)
            break;

        // Delete next N nodes
        temp = curr->next;
        for (int i = 0; i < n && temp != NULL; i++) {
            struct Node* del = temp;
            temp = temp->next;
            free(del);
        }
        curr->next = temp;
        curr = temp;
    }
    return head;
}

// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, val, m, d;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &val);
        insertEnd(&head, val);
    }

    printf("Enter M (nodes to skip) and N (nodes to delete): ");
    scanf("%d %d", &m, &d);

    printf("Original List: ");
    printList(head);

    head = deleteNafterM(head, m, d);

    printf("Modified List: ");
    printList(head);
    return 0;
}
