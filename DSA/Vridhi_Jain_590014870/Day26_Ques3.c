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

void print(struct Node* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

struct Node* sortList(struct Node* head) {
    struct Node *zeroH = NULL, *zeroT = NULL;
    struct Node *oneH = NULL, *oneT = NULL;
    struct Node *twoH = NULL, *twoT = NULL;

    while (head) {
        if (head->val == 0) {
            if (!zeroH) zeroH = zeroT = head;
            else zeroT->next = head, zeroT = head;
        } else if (head->val == 1) {
            if (!oneH) oneH = oneT = head;
            else oneT->next = head, oneT = head;
        } else {
            if (!twoH) twoH = twoT = head;
            else twoT->next = head, twoT = head;
        }
        head = head->next;
    }

    if (zeroT) zeroT->next = oneH ? oneH : twoH;
    if (oneT) oneT->next = twoH;
    if (twoT) twoT->next = NULL;

    return zeroH ? zeroH : (oneH ? oneH : twoH);
}

int main() {
    int n, x;
    struct Node* head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter values (only 0, 1, or 2):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x < 0 || x > 2) {
            printf("Only 0, 1, or 2 allowed!\n");
            i--;
            continue;
        }
        addEnd(&head, x);
    }

    head = sortList(head);
    printf("Sorted List: ");
    print(head);
    return 0;
}
