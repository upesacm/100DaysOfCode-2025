#include <stdio.h>
#include <stdlib.h>

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
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

int countNodes(struct Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

void swapKthNode(struct Node** head, int k) {
    int n = countNodes(*head);
    if (k > n || (2 * k - 1) == n) return; // Invalid or same node

    struct Node *x = *head, *x_prev = NULL;
    struct Node *y = *head, *y_prev = NULL;

    for (int i = 1; i < k; i++) {
        x_prev = x;
        x = x->next;
    }

    for (int i = 1; i < n - k + 1; i++) {
        y_prev = y;
        y = y->next;
    }

    if (x_prev) x_prev->next = y;
    if (y_prev) y_prev->next = x;

    struct Node* temp = x->next;
    x->next = y->next;
    y->next = temp;

    if (k == 1) *head = y;
    if (k == n) *head = x;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, val, k;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = insertEnd(head, val);
    }
    printf("Enter k: ");
    scanf("%d", &k);
    swapKthNode(&head, k);
    printList(head);
    return 0;
}
