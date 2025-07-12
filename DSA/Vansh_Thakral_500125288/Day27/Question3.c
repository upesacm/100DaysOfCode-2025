#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void append(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d", node->data);
        if (node->next) printf(" -> ");
        node = node->next;
    }
    printf("\n");
}

struct Node* deleteK(struct Node* head, int K) {
    if (K == 1) {
        while (head) {
            struct Node* temp = head;
            head = head->next;
            free(temp);
        }
        return NULL;
    }

    struct Node* curr = head;
    struct Node* prev = NULL;
    int count = 1;

    while (curr) {
        if (count % K == 0) {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
        count++;
    }

    return head;
}

int main() {
    struct Node* head = NULL;
    int k = 3;

    for (int i = 1; i <= 10; i++)
        append(&head, i);

    printf("Original List: ");
    printList(head);

    head = deleteK(head, k);

    printf("After removing every %d-th node: ", k);
    printList(head);

    return 0;
}
