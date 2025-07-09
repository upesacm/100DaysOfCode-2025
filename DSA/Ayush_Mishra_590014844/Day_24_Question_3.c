#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

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

struct Node* deleteAtPosition(struct Node* head, int pos) {
    if (pos <= 0 || head == NULL) return head;

    if (pos == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* curr = head;
    for (int i = 1; curr != NULL && i < pos - 1; i++)
        curr = curr->next;

    if (curr == NULL || curr->next == NULL)
        return head;

    struct Node* del = curr->next;
    curr->next = curr->next->next;
    free(del);
    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, val, pos;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &val);
        insertEnd(&head, val);
    }

    printf("Enter position to delete (1-based index): ");
    scanf("%d", &pos);

    printf("Original List: ");
    printList(head);

    head = deleteAtPosition(head, pos);

    printf("Modified List: ");
    printList(head);
    return 0;
}
