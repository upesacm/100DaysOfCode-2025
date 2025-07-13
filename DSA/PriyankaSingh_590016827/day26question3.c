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
    while (last->next != NULL) last = last->next;
    last->next = new_node;
}

void sortList(struct Node* head) {
    int count[3] = {0};
    struct Node* ptr = head;

    while (ptr != NULL) {
        count[ptr->data]++;
        ptr = ptr->next;
    }

    int i = 0;
    ptr = head;
    while (ptr != NULL) {
        if (count[i] == 0)
            ++i;
        else {
            ptr->data = i;
            --count[i];
            ptr = ptr->next;
        }
    }
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d", node->data);
        if (node->next) printf(" -> ");
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter elements (0s, 1s, 2s only):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&head, val);
    }
    sortList(head);
    printf("Sorted list:\n");
    printList(head);
    return 0;
}
