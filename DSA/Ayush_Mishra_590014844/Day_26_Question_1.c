#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insert(struct Node* head, int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    if (!head) return temp;
    struct Node* curr = head;
    while (curr->next) curr = curr->next;
    curr->next = temp;
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

struct Node* swapKth(struct Node* head, int k) {
    int n = countNodes(head);
    if (k > n || 2 * k - 1 == n) return head;

    struct Node *x_prev = NULL, *x = head;
    for (int i = 1; i < k; i++) {
        x_prev = x;
        x = x->next;
    }

    struct Node *y_prev = NULL, *y = head;
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

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, val, k;
    struct Node* head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = insert(head, val);
    }
    scanf("%d", &k);
    head = swapKth(head, k);
    printList(head);
    return 0;
}
