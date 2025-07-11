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

void insert(struct Node** head, int data) {
    struct Node* temp = newNode(data);
    temp->next = *head;
    *head = temp;
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

    zero->next = oneD->next ? oneD->next : twoD->next;
    one->next = twoD->next;
    two->next = NULL;

    struct Node* newHead = zeroD->next;

    free(zeroD);
    free(oneD);
    free(twoD);

    return newHead;
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
    struct Node* head1 = NULL;
    insert(&head1, 2);
    insert(&head1, 2);
    insert(&head1, 0);
    insert(&head1, 1);
    head1 = sortList(head1);
    printList(head1);

    struct Node* head2 = NULL;
    insert(&head2, 2);
    insert(&head2, 2);
    insert(&head2, 0);
    insert(&head2, 2);
    insert(&head2, 0);
    insert(&head2, 1);
    insert(&head2, 2);
    insert(&head2, 1);
    head2 = sortList(head2);
    printList(head2);

    return 0;
}
