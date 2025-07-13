#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* newNode(int v) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = v;
    temp->next = NULL;
    return temp;
}

void addEnd(struct Node** head, int v) {
    struct Node* temp = newNode(v);
    if (!*head) {
        *head = temp;
        return;
    }
    struct Node* cur = *head;
    while (cur->next)
        cur = cur->next;
    cur->next = temp;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

struct Node* removeKth(struct Node* head, int k) {
    if (k <= 1 || !head) return NULL;

    struct Node* cur = head;
    int count = 1;

    while (cur && cur->next) {
        if ((count + 1) % k == 0) {
            struct Node* del = cur->next;
            cur->next = del->next;
            free(del);
        } else {
            cur = cur->next;
        }
        count++;
    }

    return head;
}

int main() {
    int n, val, k;
    struct Node* head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        addEnd(&head, val);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    head = removeKth(head, k);

    printf("Updated List:\n");
    printList(head);

    return 0;
}
