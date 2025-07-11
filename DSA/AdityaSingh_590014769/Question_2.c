#include <stdio.h>

struct Node {
    int val;
    struct Node* next;
};

void bubbleSort(struct Node* head) {
    struct Node* i = head;
    while (i && i->next) {
        struct Node* j = i->next;
        while (j) {
            if (i->val > j->val) {
                int temp = i->val;
                i->val = j->val;
                j->val = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
}

struct Node* makeUnion(struct Node* head1, struct Node* head2) {
    struct Node* dummy = NULL, *tail = NULL;

    struct Node* temp = head1;
    while (temp) {
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->val = temp->val;
        newNode->next = NULL;
        if (!dummy) dummy = tail = newNode;
        else { tail->next = newNode; tail = newNode; }
        temp = temp->next;
    }

    temp = head2;
    while (temp) {
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->val = temp->val;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
        temp = temp->next;
    }

    bubbleSort(dummy);

    temp = dummy;
    while (temp && temp->next) {
        if (temp->val == temp->next->val) {
            struct Node* dup = temp->next;
            temp->next = dup->next;
            free(dup);
        } else {
            temp = temp->next;
        }
    }

    return dummy;
}
