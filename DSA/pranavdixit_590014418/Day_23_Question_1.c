#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->next = NULL;
    return node;
}

void append(struct Node** head, int val) {
    struct Node* newNode = createNode(val);
    if (!*head) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

int getKthFromEnd(struct Node* head, int k) {
    struct Node *fast = head, *slow = head;
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
    int vals[] = {1,2,3,4,5,6,7,8,9};
    for (int i = 0; i < 9; i++) append(&head, vals[i]);

    int k = 2;
    int result = getKthFromEnd(head, k);
    printf("K = %d, Kth from end: %d\n", k, result);

    struct Node* head2 = NULL;
    int vals2[] = {10, 5, 100, 5};
    for (int i = 0; i < 4; i++) append(&head2, vals2[i]);

    k = 5;
    result = getKthFromEnd(head2, k);
    printf("K = %d, Kth from end: %d\n", k, result);

    return 0;
}
