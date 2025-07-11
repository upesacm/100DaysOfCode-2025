#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insert(struct Node** head_ref, int data) {
    struct Node* temp = newNode(data);
    temp->next = *head_ref;
    *head_ref = temp;
}

struct Node* sortList(struct Node* head) {
    struct Node *zeroD = newNode(0), *oneD = newNode(0), *twoD = newNode(0);
    struct Node *zero = zeroD, *one = oneD, *two = twoD;

    while (head) {
        if (head->data == 0) {
            zero->next = head;
            zero = zero->next;
        } else if (head->data == 1) {
            one->next = head;
            one = one->next;
        } else {
            two->next = head;
            two = two->next;
        }
        head = head->next;
    }

    two->next = NULL;
    one->next = twoD->next;
    zero->next = oneD->next;

    struct Node* sorted = zeroD->next;

    free(zeroD);
    free(oneD);
    free(twoD);

    return sorted;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insert(&head, 2);
    insert(&head, 2);
    insert(&head, 0);
    insert(&head, 1);

    head = sortList(head);
    printList(head);

    return 0;
}
