#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void append(struct Node** headRef, int data) {
    struct Node* temp = newNode(data);
    if (*headRef == NULL) {
        *headRef = temp;
        return;
    }
    struct Node* current = *headRef;
    while (current->next != NULL)
        current = current->next;
    current->next = temp;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next) printf("->");
        head = head->next;
    }
    printf("\n");
}

struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    struct Node* result = NULL;
    struct Node** tail = &result;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data == head2->data) {
            *tail = newNode(head1->data);
            tail = &((*tail)->next);
            head1 = head1->next;
            head2 = head2->next;
        } else if (head1->data < head2->data) {
            head1 = head1->next;
        } else {
            head2 = head2->next;
        }
    }
    return result;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    append(&list1, 1);
    append(&list1, 2);
    append(&list1, 3);
    append(&list1, 4);
    append(&list1, 6);

    append(&list2, 2);
    append(&list2, 4);
    append(&list2, 6);
    append(&list2, 8);

    struct Node* intersection = getIntersection(list1, list2);

    printList(intersection);

    return 0;
}
