#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* newNode(int val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->val = val;
    n->next = NULL;
    return n;
}

void insertEnd(struct Node** head, int val) {
    struct Node* temp = newNode(val);
    if (!*head) *head = temp;
    else {
        struct Node* curr = *head;
        while (curr->next) curr = curr->next;
        curr->next = temp;
    }
}

struct Node* findIntersection(struct Node* a, struct Node* b) {
    struct Node* result = NULL, *tail = NULL;
    while (a && b) {
        if (a->val < b->val) a = a->next;
        else if (b->val < a->val) b = b->next;
        else {
            struct Node* temp = newNode(a->val);
            if (!result) result = tail = temp;
            else tail->next = temp, tail = temp;
            a = a->next;
            b = b->next;
        }
    }
    return result;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next) printf("->");
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n1, n2, val;
    struct Node *head1 = NULL, *head2 = NULL;

    printf("Enter number of nodes in List 1: ");
    scanf("%d", &n1);
    printf("Enter sorted values for List 1:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        insertEnd(&head1, val);
    }

    printf("Enter number of nodes in List 2: ");
    scanf("%d", &n2);
    printf("Enter sorted values for List 2:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        insertEnd(&head2, val);
    }

    struct Node* intersection = findIntersection(head1, head2);

    printf("Intersection: ");
    if (!intersection)
        printf("None\n");
    else
        printList(intersection);

    return 0;
}
