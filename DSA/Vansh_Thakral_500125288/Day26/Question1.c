#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int countNodes(struct Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* swapKth(struct Node* head, int k) {
    int n = countNodes(head);
    if (k > n) return head;
    if (2 * k - 1 == n) return head;

    struct Node *x = head, *x_prev = NULL;
    for (int i = 1; i < k; i++) {
        x_prev = x;
        x = x->next;
    }

    struct Node *y = head, *y_prev = NULL;
    for (int i = 1; i < n - k + 1; i++) {
        y_prev = y;
        y = y->next;
    }

    if (x_prev) x_prev->next = y;
    if (y_prev) y_prev->next = x;

    struct Node* temp = x->next;
    x->next = y->next;
    y->next = temp;

    if (k == 1) head = y;
    if (k == n) head = x;

    return head;
}
