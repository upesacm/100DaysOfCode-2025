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

void removeDuplicates(struct Node* head) {
    struct Node* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp); 
        } else {
            current = current->next;
        }
    }
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) printf(" -> ");
        current = current->next;
    }
    printf("\n");
}

struct Node* createExampleList() {
    struct Node* head = newNode(2);
    head->next = newNode(2);
    head->next->next = newNode(2);
    head->next->next->next = newNode(2);
    return head;
}

int main() {
    struct Node* head = createExampleList();

    printf("Original list:\n");
    printList(head);

    removeDuplicates(head);

    printf("After removing duplicates:\n");
    printList(head);

    return 0;
}
