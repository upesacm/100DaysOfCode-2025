#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* deleteAt(struct Node* head, int x) {
    if (x == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* curr = head;
    for (int i = 1; i < x - 1 && curr != NULL; i++)
        curr = curr->next;

    if (curr != NULL && curr->next != NULL) {
        struct Node* temp = curr->next;
        curr->next = temp->next;
        free(temp);
    }

    return head;
}

void print(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, x, val;
    struct Node *head = NULL, *last = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        if (head == NULL)
            head = last = newNode;
        else {
            last->next = newNode;
            last = newNode;
        }
    }

    scanf("%d", &x);
    head = deleteAt(head, x);
    print(head);
    return 0;
}
