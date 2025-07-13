#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
};

struct Node* new(int v) {
    struct Node* n = malloc(sizeof(struct Node));
    n->val = v;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

void addEnd(struct Node** head, int v) {
    struct Node* temp = new(v);
    if (!*head) *head = temp;
    else {
        struct Node* cur = *head;
        while (cur->next) cur = cur->next;
        cur->next = temp;
        temp->prev = cur;
    }
}

struct Node* delAt(struct Node* head, int pos) {
    if (!head || pos <= 0) return head;
    struct Node* cur = head;

    for (int i = 1; cur && i < pos; i++)
        cur = cur->next;

    if (!cur) return head;

    if (cur->prev) cur->prev->next = cur->next;
    else head = cur->next;

    if (cur->next) cur->next->prev = cur->prev;

    free(cur);
    return head;
}

void print(struct Node* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(" <--> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, val, pos;
    struct Node* head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        addEnd(&head, val);
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    head = delAt(head, pos);

    printf("Updated List: ");
    print(head);
    return 0;
}
