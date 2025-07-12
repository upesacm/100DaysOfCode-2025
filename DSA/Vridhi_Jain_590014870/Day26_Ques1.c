#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* new(int v) {
    struct Node* n = malloc(sizeof(struct Node));
    n->val = v;
    n->next = NULL;
    return n;
}

void addEnd(struct Node** head, int v) {
    struct Node* temp = new(v);
    if (!*head) *head = temp;
    else {
        struct Node* curr = *head;
        while (curr->next) curr = curr->next;
        curr->next = temp;
    }
}

int count(struct Node* head) {
    int c = 0;
    while (head) {
        c++;
        head = head->next;
    }
    return c;
}

void swapK(struct Node** head, int k) {
    int n = count(*head);
    if (k > n || 2 * k - 1 == n) return;

    struct Node *a = *head, *b = *head;
    struct Node *prevA = NULL, *prevB = NULL;

    for (int i = 1; i < k; i++) {
        prevA = a;
        a = a->next;
    }

    for (int i = 1; i < n - k + 1; i++) {
        prevB = b;
        b = b->next;
    }

    if (prevA) prevA->next = b;
    else *head = b;

    if (prevB) prevB->next = a;
    else *head = a;

    struct Node* temp = a->next;
    a->next = b->next;
    b->next = temp;
}

void print(struct Node* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next) printf("->");
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, x, k;
    struct Node* head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        addEnd(&head, x);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    swapK(&head, k);

    printf("Updated List: ");
    print(head);
    return 0;
}
