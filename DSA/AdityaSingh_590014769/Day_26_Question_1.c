#include <stdio.h>

struct Node {
    int val;
    struct Node* next;
};

void swapKth(struct Node* head, int k) {
    int count = 0;
    struct Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }

    if (k > count) return;
    if (2 * k - 1 == count) return; //  Using the Same node

    struct Node* x = head;
    struct Node* y = head;
    struct Node *xPrev = NULL, *yPrev = NULL;

    for (int i = 1; i < k; i++) {
        xPrev = x;
        x = x->next;
    }
    for (int i = 1; i < count - k + 1; i++) {
        yPrev = y;
        y = y->next;
    }

    if (xPrev) xPrev->next = y;
    if (yPrev) yPrev->next = x;

    struct Node* tempNext = x->next;
    x->next = y->next;
    y->next = tempNext;
}
