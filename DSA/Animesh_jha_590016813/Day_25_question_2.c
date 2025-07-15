#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insertAtEnd(struct Node** headRef, int data) {
    struct Node* node = newNode(data);
    if (*headRef == NULL) {
        *headRef = node;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next)
        temp = temp->next;
    temp->next = node;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    struct Node* result = NULL;

    while (head1 && head2) {
        if (head1->data == head2->data) {
            insertAtEnd(&result, head1->data);
            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->data < head2->data) {
            head1 = head1->next;
        }
        else {
            head2 = head2->next;
        }
    }

    return result;
}
int main() {
    struct Node* head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = newNode(6);

    struct Node* head2 = newNode(2);
    head2->next = newNode(4);
    head2->next->next = newNode(6);
    head2->next->next->next = newNode(8);

    printf("LinkedList1: ");
    printList(head1);

    printf("LinkedList2: ");
    printList(head2);

    struct Node* intersection = findIntersection(head1, head2);

    printf("Intersection: ");
    printList(intersection);

    return 0;
}
