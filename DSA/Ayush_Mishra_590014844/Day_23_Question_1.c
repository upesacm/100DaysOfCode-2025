#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

int findKthFromEnd(struct Node* head, int k) {
    struct Node* fast = head;
    struct Node* slow = head;

    for (int i = 0; i < k; i++) {
        if (!fast) return -1;
        fast = fast->next;
    }

    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    return slow ? slow->data : -1;
}

int main() {
    struct Node* head = NULL;
    int n, val, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d node values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&head, val);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    int result = findKthFromEnd(head, k);
    printf("Kth node from end: %d\n", result);

    return 0;
}
