#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    return new;
}

void insert(struct Node** head, int data) {
    struct Node* new = createNode(data);
    if (*head == NULL) {
        *head = new;
        return;
    }
    struct Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = new;
}

struct Node* intersection(struct Node* a, struct Node* b) {
    struct Node* res = NULL;
    while (a && b) {
        if (a->data == b->data) {
            insert(&res, a->data);
            a = a->next;
            b = b->next;
        } else if (a->data < b->data) {
            a = a->next;
        } else {
            b = b->next;
        }
    }
    return res;
}

void print(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf("->");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* a = NULL;
    struct Node* b = NULL;
    int n1, n2, x;

    printf("Enter number of elements in list 1: ");
    scanf("%d", &n1);
    printf("Enter %d sorted values:\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &x);
        insert(&a, x);
    }

    printf("Enter number of elements in list 2: ");
    scanf("%d", &n2);
    printf("Enter %d sorted values:\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &x);
        insert(&b, x);
    }

    struct Node* res = intersection(a, b);
    print(res);

    return 0;
}
