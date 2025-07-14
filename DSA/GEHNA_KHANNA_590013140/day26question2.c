#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    return n;
}

void addLast(struct Node** head, int data) {
    struct Node* n = newNode(data);
    if (*head == NULL) {
        *head = n;
        return;
    }
    struct Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = n;
}

int exists(struct Node* head, int val) {
    while (head) {
        if (head->data == val) return 1;
        head = head->next;
    }
    return 0;
}

void insertSorted(struct Node** head, int val) {
    if (exists(*head, val)) return;
    struct Node* n = newNode(val);
    if (*head == NULL || (*head)->data > val) {
        n->next = *head;
        *head = n;
        return;
    }
    struct Node* temp = *head;
    while (temp->next && temp->next->data < val)
        temp = temp->next;
    n->next = temp->next;
    temp->next = n;
}

struct Node* getUnion(struct Node* a, struct Node* b) {
    struct Node* result = NULL;
    while (a) {
        insertSorted(&result, a->data);
        a = a->next;
    }
    while (b) {
        insertSorted(&result, b->data);
        b = b->next;
    }
    return result;
}

void print(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, m, x;
    struct Node *l1 = NULL, *l2 = NULL;

    printf("Enter size of list 1: ");
    scanf("%d", &n);
    printf("Enter elements of list 1: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        addLast(&l1, x);
    }

    printf("Enter size of list 2: ");
    scanf("%d", &m);
    printf("Enter elements of list 2: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        addLast(&l2, x);
    }

    struct Node* result = getUnion(l1, l2);

    printf("Union List:\n");
    print(result);

    return 0;
}
