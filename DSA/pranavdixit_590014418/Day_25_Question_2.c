#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

void append(struct Node** head, int val) {
    struct Node* temp = newNode(val);
    if (*head == NULL) {
        *head = temp;
        return;
    }
    struct Node* curr = *head;
    while (curr->next)
        curr = curr->next;
    curr->next = temp;
}

struct Node* getIntersection(struct Node* a, struct Node* b) {
    struct Node* result = NULL;
    struct Node* tail = NULL;

    while (a && b) {
        if (a->data == b->data) {
            if (result == NULL) {
                result = newNode(a->data);
                tail = result;
            } else {
                tail->next = newNode(a->data);
                tail = tail->next;
            }
            a = a->next;
            b = b->next;
        } else if (a->data < b->data) {
            a = a->next;
        } else {
            b = b->next;
        }
    }

    return result;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
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

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    struct Node* intersect = getIntersection(list1, list2);

    printf("Intersection: ");
    printList(intersect);

    return 0;
}
