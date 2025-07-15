#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* swapKth(struct Node* head, int k) {
    int n = 0;
    struct Node* temp = head;
    while (temp) {
        n++;
        temp = temp->next;
    }
    if (k > n || 2 * k - 1 == n) return head;

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

    struct Node* temp2 = x->next;
    x->next = y->next;
    y->next = temp2;

    if (k == 1) head = y;
    if (k == n) head = x;

    return head;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf("->");
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, k, val;
    struct Node *head = NULL, *curr = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = create(val);
        if (head == NULL) {
            head = newNode;
            curr = head;
        } else {
            curr->next = newNode;
            curr = curr->next;
        }
    }

    printf("Enter k: ");
    scanf("%d", &k);

    head = swapKth(head, k);
    printList(head);

    return 0;
}
