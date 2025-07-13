#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
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
        if (node->next) printf(" <--> ");
        node = node->next;
    }
    printf("\n");
}


struct Node* deleteNode(struct Node* head, int x) {
    if (!head) return NULL;

    struct Node* temp = head;

    if (x == 1) {
        head = head->next;
        if (head) head->prev = NULL;
        free(temp);
        return head;
    }

    for (int i = 1; temp && i < x; i++)
        temp = temp->next;

    if (!temp) return head;

    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;

    free(temp);
    return head;
}


int main() {
    struct Node* head = NULL;
    append(&head, 1);
    append(&head, 5);
    append(&head, 2);
    append(&head, 9);

    printf("Original List: ");
    printList(head);

    int pos = 1;
    head = deleteNode(head, pos);

    printf("After deleting position %d: ", pos);
    printList(head);

    return 0;
}

