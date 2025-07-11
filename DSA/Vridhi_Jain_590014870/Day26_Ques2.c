#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

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

void addEnd(struct Node** h, int v) {
    struct Node* temp = new(v);
    if (!*h) *h = temp;
    else {
        struct Node* c = *h;
        while (c->next) c = c->next;
        c->next = temp;
    }
}

void print(struct Node* h) {
    while (h) {
        printf("%d", h->val);
        if (h->next) printf(" -> ");
        h = h->next;
    }
    printf("\n");
}

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

struct Node* makeUnion(struct Node* a, struct Node* b) {
    int temp[MAX], count = 0;

    while (a) {
        temp[count++] = a->val;
        a = a->next;
    }
    while (b) {
        temp[count++] = b->val;
        b = b->next;
    }

    qsort(temp, count, sizeof(int), cmp);

    struct Node* result = NULL;
    for (int i = 0; i < count; i++) {
        if (i == 0 || temp[i] != temp[i - 1])
            addEnd(&result, temp[i]);
    }

    return result;
}

int main() {
    int n1, n2, x;
    struct Node *l1 = NULL, *l2 = NULL;

    printf("Enter number of nodes in List 1: ");
    scanf("%d", &n1);
    printf("Enter values for List 1:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &x);
        addEnd(&l1, x);
    }

    printf("Enter number of nodes in List 2: ");
    scanf("%d", &n2);
    printf("Enter values for List 2:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &x);
        addEnd(&l2, x);
    }

    struct Node* unionList = makeUnion(l1, l2);
    printf("Union: ");
    print(unionList);
    return 0;
}
