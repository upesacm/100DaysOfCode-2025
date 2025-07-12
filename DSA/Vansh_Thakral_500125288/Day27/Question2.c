#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void append(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    new_node->prev = last;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d", node->data);
        if (node->next) printf(" <-> ");
        node = node->next;
    }
    printf("\n");
}

struct Node* reverseDLL(struct Node* head) {
    struct Node* temp = NULL;
    struct Node* current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    if (temp != NULL)
        head = temp->prev;

    return head;
}

int main() {
    struct Node* head = NULL;
    append(&head, 75);
    append(&head, 122);
    append(&head, 59);
    append(&head, 196);

    printf("Original List: ");
    printList(head);

    head = reverseDLL(head);

    printf("Reversed List: ");
    printList(head);

    return 0;
}
