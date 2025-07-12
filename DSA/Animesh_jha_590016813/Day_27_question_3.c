#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* removeKthNode(struct Node* head, int k) {
    if (head == NULL || k <= 0)
        return head;

    if (k == 1) {
        while (head != NULL) {
            struct Node* temp = head;
            head = head->next;
            free(temp);
        }
        return NULL;
    }

    struct Node* current = head;
    struct Node* prev = NULL;
    int count = 1;

    while (current != NULL) {
        if (count % k == 0) {
            prev->next = current->next;
            free(current);
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
        count++;
    }
    return head;
}

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    for (int i = 1; i <= 8; i++) {
        head = insertEnd(head, i);
    }

    int k = 2;

    printf("Original list:\n");
    printList(head);

    head = removeKthNode(head, k);

    printf("List after removing every %dth node:\n", k);
    printList(head);

    return 0;
}
 
