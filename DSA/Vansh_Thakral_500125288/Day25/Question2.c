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

struct Node* insertEnd(struct Node* head, int data) {
    if (!head) return newNode(data);
    struct Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode(data);
    return head;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* intersect(struct Node* head1, struct Node* head2) {
    struct Node* dummy = newNode(0);
    struct Node* tail = dummy;

    while (head1 && head2) {
        if (head1->data == head2->data) {
            tail->next = newNode(head1->data);
            tail = tail->next;
            head1 = head1->next;
            head2 = head2->next;
        } else if (head1->data < head2->data) {
            head1 = head1->next;
        } else {
            head2 = head2->next;
        }
    }
    return dummy->next;
}

int main() {
    struct Node* l1 = NULL;
    struct Node* l2 = NULL;


    l1 = insertEnd(l1, 1);
    l1 = insertEnd(l1, 2);
    l1 = insertEnd(l1, 3);
    l1 = insertEnd(l1, 4);
    l1 = insertEnd(l1, 6);


    l2 = insertEnd(l2, 2);
    l2 = insertEnd(l2, 4);
    l2 = insertEnd(l2, 6);
    l2 = insertEnd(l2, 8);

    struct Node* result = intersect(l1, l2);

    printf("Intersection: ");
    printList(result);

    return 0;
}
