#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
};

struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = val;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void addEnd(struct Node** head, int val) {
    struct Node* temp = newNode(val);
    if (*head == NULL) {
        *head = temp;
        return;
    }
    struct Node* curr = *head;
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr;
}

struct Node* reverseDLL(struct Node* head) {
    struct Node* curr = head;
    struct Node* temp = NULL;

    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if (temp != NULL)
        head = temp->prev;

    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL)
            printf(" <-> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, val;
    struct Node* head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        addEnd(&head, val);
    }

    head = reverseDLL(head);

    printf("Reversed List:\n");
    printList(head);

    return 0;
}
