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

void addEnd(struct Node** h, int v) {
    struct Node* t = new(v);
    if (!*h) *h = t;
    else {
        struct Node* c = *h;
        while (c->next) c = c->next;
        c->next = t;
    }
}

struct Node* rev(struct Node* h) {
    struct Node *p = NULL, *n;
    while (h) {
        n = h->next;
        h->next = p;
        p = h;
        h = n;
    }
    return p;
}

struct Node* addLL(struct Node* a, struct Node* b) {
    a = rev(a);
    b = rev(b);
    struct Node *res = NULL, *t = NULL;
    int sum, carry = 0;
    while (a || b || carry) {
        int x = a ? a->val : 0;
        int y = b ? b->val : 0;
        sum = x + y + carry;
        carry = sum / 10;
        addEnd(&res, sum % 10);
        if (a) a = a->next;
        if (b) b = b->next;
    }
    return rev(res);
}

void print(struct Node* h) {
    while (h && h->val == 0) h = h->next;
    if (!h) printf("0");
    while (h) {
        printf("%d", h->val);
        if (h->next) printf("->");
        h = h->next;
    }
    printf("\n");
}

int main() {
    int n1, n2, x;
    struct Node *a = NULL, *b = NULL;

    printf("Enter number of digits in num1: ");
    scanf("%d", &n1);
    printf("Enter digits for num1:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &x);
        addEnd(&a, x);
    }

    printf("Enter number of digits in num2: ");
    scanf("%d", &n2);
    printf("Enter digits for num2:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &x);
        addEnd(&b, x);
    }

    struct Node* sum = addLL(a, b);
    printf("Sum: ");
    print(sum);
    return 0;
}
