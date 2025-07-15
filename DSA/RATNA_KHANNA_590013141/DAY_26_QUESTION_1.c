#include <stdio.h>
#include <stdlib.h>

struct Node {
    int d;
    struct Node* n;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->d = val;
    node->n = NULL;
    return node;
}

void insertEnd(struct Node** head, int val) {
    struct Node* node = newNode(val);
    if (*head == NULL) {
        *head = node;
        return;
    }
    struct Node* temp = *head;
    while (temp->n)
        temp = temp->n;
    temp->n = node;
}

struct Node* swapK(struct Node* head, int k,int n) {
    int l = n;
    if (k > l || 2 * k - 1 == l) return head;

    struct Node *px = NULL, *x = head;
    for (int i = 1; i < k; i++) {
        px = x;
        x = x->n;
    }

    struct Node *py = NULL, *y = head;
    for (int i = 1; i < l - k + 1; i++) {
        py = y;
        y = y->n;
    }

    if (px) px->n = y;
    else head = y;

    if (py) py->n = x;
    else head = x;

    struct Node* tmp = x->n;
    x->n = y->n;
    y->n = tmp;

    return head;
}

void print(struct Node* head) {
    while (head) {
        printf("%d ", head->d);
        head = head->n;
    }
    printf("\n");
}

int main() 
{
    struct Node* head = NULL;
    int n, val, k;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter node values:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        insertEnd(&head, val);
    }
    printf("Enter value of k: ");
    scanf("%d", &k);
    printf("Original List: ");
    print(head);
    head = swapK(head, k,n);
    printf("Modified List: ");
    print(head);
    return 0;
}
